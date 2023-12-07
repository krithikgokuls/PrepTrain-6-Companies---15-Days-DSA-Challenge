/*
	Time Complexity : O(N)
	Space Complexity : O(N)

	Where 'N' is the length of the string.
*/

bool isValidParenthesis(string s) 
{   
    // Make an inbuilt stack.
    stack<char> st; 
    char x; 
  
    // Traversing int 's'.
    for (int i = 0; i < s.length(); i++)  
    { 
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')  
        { 
            // Push the element in the stack .
            st.push(s[i]); 
            continue; 
        } 
  
        /* 
            If current current character is not opening 
            bracket, then it must be closing. So stack 
            cannot be empty at this point. 
        */

        if (st.empty()) 
        {
            return false; 
        }
  		
        // Store the top element.
        x = st.top(); 
        st.pop(); 
        
        // Check for opening braces in stack of corresponding closing braces.
        switch (s[i]) { 
        case ')': 
            
            if (x == '{' || x == '[') 
            {
                return false; 
            }
            break; 
  
        case '}': 
  
            if (x == '(' || x == '[') 
            {
                return false; 
            }
            break; 
  
        case ']': 
            
            if (x == '(' || x == '{')
            {
                return false;
            }
            break; 
        } 
    } 
  
    // Check Empty Stack.
    return (st.empty()); 
} 
