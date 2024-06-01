#!/usr/bin/env bash

# Get script location folder
SOURCE=${BASH_SOURCE[0]}
while [ -L "$SOURCE" ]; do
  DIR=$(cd -P "$(dirname "$SOURCE")" >/dev/null 2>&1 && pwd)
  SOURCE=$(readlink "$SOURCE")
  [[ $SOURCE != /* ]] && SOURCE=$DIR/$SOURCE
done
DIR=$(cd -P "$(dirname "$SOURCE")" >/dev/null 2>&1 && pwd)

# Init path to file
CODING_STYLE="$DIR/coding-style.sh"
REPORTS="$DIR/reports.log"
REPORTS_CLEAN="$DIR/reports-clean.log"

# Ensure Docker is installed
if ! command -v docker &> /dev/null; then
  echo "Docker is not installed. Please install Docker first."
  exit 1
fi

# Ensure Docker is running
if ! sudo systemctl is-active --quiet docker; then
  echo "Starting Docker..."
  sudo systemctl start docker
  if [ $? -ne 0 ]; then
    exit 1
  fi
fi

# Fetch default coding style
echo "Fetching latest coding style..."
$CODING_STYLE . . >/dev/null
if [ $? -ne 0 ]; then
  exit 1
fi
mv -f "$(pwd)/coding-style-reports.log" $REPORTS

# Skip ignored file from the .gitignore
git rev-parse --git-dir > /dev/null 2>&1
if [ $? -eq 0 ]; then
  FILTER="$(cat $REPORTS | grep "$(git status --short| grep  '^?' | cut -d\  -f2- | git ls-files)")"
else
  FILTER="$(cat $REPORTS)"
fi

# Improve human readability
echo "Cleaning reports..."
while true; do
  l="$(echo "$FILTER" | head -1)"
  if [ -z "$l" ]; then
    break
  fi
  ERROR="$(echo "$l" | cut -d ":" -f 3,4 | cut -c2-)"

  FILE="$(echo "$FILTER" | grep "$ERROR" | awk -F ":" '{ printf "  l%-5s %s\n", $2, $1 }')"
  FILTER="$(echo "$FILTER" | grep -v "$ERROR")"

  # Set the color depending of the error type
  case "$(echo "$ERROR" | cut -d ":" -f 1)" in
    "FATAL") COLOR="\033[35m"
    ;;
    "MAJOR") COLOR="\033[31m"
    ;;
    "MINOR") COLOR="\033[93m"
    ;;
    "INFO") COLOR="\033[34m"
    ;;
  esac

  CLEAN="$(printf "$CLEAN\n\n$(echo "$ERROR" | awk -F ":" -v COLOR="$COLOR" '{ printf "%s[%-5s %s]\033[0m", COLOR, $1, $2 }')\n$FILE")"
done

# Set to report
if [ ! "" = "$CLEAN" ]; then
  echo "$CLEAN" | tail -n +3 > $REPORTS_CLEAN
else
  echo -e "\033[32mNo coding style error found\033[0m" > $REPORTS_CLEAN
fi
cat $REPORTS_CLEAN

