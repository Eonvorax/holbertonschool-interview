#!/usr/bin/python3
"""
Log parsing
"""
import sys


def print_statistics():
    """
    Print accumulated statistics.
    """
    print(f"File size: {total_file_size}")
    for code in sorted(status_code_counts.keys()):
        if status_code_counts[code] > 0:
            print(f"{code}: {status_code_counts[code]}")
    sys.stdout.flush()  # Ensure the output is immediately visible


def process_line(line):
    """
    Parse a log line and update metrics.
    """
    global total_file_size
    try:
        # Parse line into parts
        parts = line.split()
        if len(parts) < 2:
            return  # Skip invalid line

        # Extract and validate components
        status_code = int(parts[-2])  # Status code
        file_size = int(parts[-1])   # File size

        # Update metrics
        if status_code in status_code_counts:
            status_code_counts[status_code] += 1
        total_file_size += file_size
    except (IndexError, ValueError):
        pass  # Skip invalid lines

if __name__ == "__main__":
    # Initialize metrics
    total_file_size = 0
    status_code_counts = {200: 0, 301: 0, 400: 0,
                          401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            process_line(line.strip())
            line_count += 1
            if line_count % 10 == 0:
                print_statistics()
    except KeyboardInterrupt:
        # Print statistics on interruption
        print_statistics()
        raise
    finally:
        # Print final statistics at EOF
        print_statistics()
