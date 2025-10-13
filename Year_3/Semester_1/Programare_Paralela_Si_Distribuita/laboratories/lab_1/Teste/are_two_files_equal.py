def are_files_equal(file1_path, file2_path):
    """Check if two files are equal by comparing their content byte-by-byte."""
    try:
        with open(file1_path, 'rb') as file1, open(file2_path, 'rb') as file2:
            while True:
                # Read a chunk of data from both files
                chunk1 = file1.read(4096)
                chunk2 = file2.read(4096)
                
                # If both chunks are empty, files are identical
                if not chunk1 and not chunk2:
                    return True, None

                # If one chunk is different from the other, files are not equal
                if chunk1 != chunk2:
                    return False, None
    except FileNotFoundError:
        return False, "One or both files do not exist."
    except Exception as e:
        return False, str(e)

# Example usage:
try:
    result, error = are_files_equal('outputs\\c++\\output_date10x10.txt', 'outputs\\java\\output_date10x10.txt')
    if not result:
        raise AssertionError(error)
    result, error = are_files_equal('outputs\\c++\\output_date1000x1000.txt', 'outputs\\java\\output_date1000x1000.txt')
    if not result:
        raise AssertionError(error)
    result, error = are_files_equal('outputs\\c++\\output_date10000x10000.txt', 'outputs\\java\\output_date10000x10000.txt')
    if not result:
        raise AssertionError(error)
    result, error = are_files_equal('outputs\\c++\\output_date10x10000.txt', 'outputs\\java\\output_date10x10000.txt')
    if not result:
        raise AssertionError(error)
    result, error = are_files_equal('outputs\\c++\\output_date10000x10.txt', 'outputs\\java\\output_date10000x10.txt')
    if not result:
        raise AssertionError(error)
    print("All files are equal")
except AssertionError as e:
    print(f"Files are not equal: {e}")
except Exception as e:
    print(f"An error occurred: {e}")