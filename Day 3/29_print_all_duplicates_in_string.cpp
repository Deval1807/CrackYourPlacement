/*
Link: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
Method 1: Hashing 
Time Complexity: O(n)
Space Complexity: O(n)
*/

void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        // increase the count of character str[i] by 1
        count[str[i]]++;
    }
    // iterating through the unordered map
    for (auto it : count) {
        // if the count of characters is greater than 1 then
        // duplicate found
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}


/*
Method 2: Sorting 
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/

void printDuplicates(string str)
{
    int len = str.length();

    // Sorting the string
    sort(str.begin(), str.end());

    // Loop through the sorted string to find duplicates
    for (int i = 0; i < len; i++) {
        int count = 1;

        // Counting the occurrences of each character
        while (i < len - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // Printing the duplicate character and its count
        if (count > 1) {
            cout << str[i] << ", count = " << count << endl;
        }
    }
}