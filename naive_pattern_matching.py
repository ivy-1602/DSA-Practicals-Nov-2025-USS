"""
Naive String Matching Algorithm
Problem: Find all occurrences of pattern in text
Time Complexity: O(n*m) where n=text length, m=pattern length
Space Complexity: O(1)
"""

def naive_search(text, pattern):
    """
    Search for pattern in text using naive approach
    Args:
        text: main string to search in
        pattern: substring to find
    """
    n = len(text)
    m = len(pattern)
    
    found = False
    
    # Slide pattern over text one by one
    for i in range(n - m + 1):
        # Check if pattern matches at position i
        if text[i:i+m] == pattern:
            print(f"Pattern found at index {i}")
            found = True
    
    if not found:
        print("Pattern not found in text")

# Driver code
if __name__ == "__main__":
    text = "ABABDABACDABABCABAB"
    pattern = "ABAB"
    
    print("Text:", text)
    print("Pattern:", pattern)
    print("\nSearching...\n")
    
    naive_search(text, pattern)
    
    print("\nAlgorithm:")
    print("- Slide pattern over text character by character")
    print("- Compare pattern with substring at each position")
    print("- Report all matches found")
