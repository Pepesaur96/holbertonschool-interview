#!/usr/bin/python3
"""UTF-8 Validation"""


def validUTF8(data):
    """
    Determines if a given dataset represents a valid UTF-8 encoding.

    UTF-8 is a variable width character encoding capable of encoding
    all 1,112,064 valid code points in Unicode
    using one to four 8-bit bytes. The encoding is defined by the Unicode
    standard, and was originally
    designed by Ken Thompson and Rob Pike.

    Rules for UTF-8 encoding:
    - For a 1-byte character, the first bit is a 0, followed by its
    Unicode code.
    - For an n-byte character (n > 1), the first byte starts with n
    ones and a zero. The following bytes all start with '10'.

    Args:
        data (list of int): A list of integers, where each integer
        represents one byte of data.
                            Only the 8 least significant bits of each
                            integer are considered.

    Returns:
        bool: True if the data is a valid UTF-8 encoding, False otherwise.
    """
    # Number of bytes in the current UTF-8 character
    num_bytes = 0

    # Masks to check the bits
    mask1 = 1 << 7
    mask2 = 1 << 6

    for num in data:
        # Mask to get the significant 8 bits
        mask = 1 << 7
        if num_bytes == 0:
            while mask & num:
                num_bytes += 1
                mask = mask >> 1

            # 1 byte characters
            if num_bytes == 0:
                continue

            # Invalid scenarios according to UTF-8
            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            # Check if the next bytes start with '10'
            if not (num & mask1 and not (num & mask2)):
                return False

        num_bytes -= 1

    # Check if all bytes are accounted for
    return num_bytes == 0
