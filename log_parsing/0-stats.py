#!/usr/bin/python3
"""
Log parsing
"""
import sys
import signal


def print_statistics():
    """
    Print accumulated statistics.
    """
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")


def process_line(line):
    """
    Parse a log line and update metrics.
    """
    global total_file_size
    try:
        # Parse line according to the given format
        parts = line.split()
        if len(parts) < 7:
            return  # Skip invalid line
        ip, _, _, date, request, status_code, file_size = parts[0], parts[1],
        parts[2], parts[3], parts[4], parts[-2], parts[-1]

        # Validate and process status code and file size
        status_code = int(status_code)
        file_size = int(file_size)

        if status_code in status_code_counts:
            status_code_counts[status_code] += 1
        total_file_size += file_size
    except Exception:
        pass  # Ignore lines that don't match the format


def signal_handler(sig, frame):
    """
    Handle keyboard interrupt (Ctrl + C) gracefully.
    """
    print_statistics()
    sys.exit(0)


if __name__ == "__main__":
    # Initialize metrics
    total_file_size = 0
    status_code_counts = {200: 0, 301: 0, 400: 0,
                          401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    # Register signal handler for Ctrl + C
    signal.signal(signal.SIGINT, signal_handler)

    # Process stdin line by line
    try:
        for line in sys.stdin:
            process_line(line.strip())
            line_count += 1
            if line_count % 10 == 0:
                print_statistics()
    except Exception as e:
        sys.stderr.write(f"Error: {e}\n")
