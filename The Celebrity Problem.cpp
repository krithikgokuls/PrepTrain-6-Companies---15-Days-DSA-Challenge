/*
    Time complexity: O(N)
    Space complexity: O(1)
    
    Where 'N' is the number of people at the party.
*/

int findCelebrity(int n) {
    
    // Two pointers pointing at start and end of search space.
    int p = 0, q = n-1; 

    // Finding celebrity.
    while(p < q) {
        if(knows(p, q)) {
            // This means p cannot be celebrity.
            p++;  
        }
        else {
            // This means q cannot be celebrity.
            q--; 
        }
    }

    int celebrity = p;
    bool knowAny = false, knownToAll = true;

    // Verify whether the celebrity knows any other person.
    for(int i = 0; i < n; i++) {
        if(knows(celebrity, i)) {
            knowAny = true;
            break;
        }
    }

    // Verify whether the celebrity is known to all the other person.
    for(int i = 0; i < n; i++) {
        if(i != celebrity and !knows(i, celebrity)) {
            knownToAll = false;
            break;
        }
    }

    if(knowAny or !knownToAll) {
        // If verificatin failed, then it means there is no celebrity at the party.
        celebrity = -1;
    }

    return celebrity;
}
