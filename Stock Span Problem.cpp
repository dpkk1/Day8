//Stock Span Problem

vector <int> calculateSpan(int price[], int n)
{
   stack<int> st; 
   vector<int>S;
	st.push(0); 
	// Span value of first element is always 1 
	S.push_back(1);
	// Calculate span values for rest of the elements 
	for (int i = 1; i < n; i++) { 
		// Pop elements from stack while stack is not 
		// empty and top of stack is smaller than 
		// price[i] 
		while (!st.empty() && price[st.top()] <= price[i]) 
			st.pop(); 

		// If stack becomes empty, then price[i] is 
		// greater than all elements on left of it, 
		// i.e., price[0], price[1], ..price[i-1]. Else 
		// price[i] is greater than elements after 
		// top of stack 
        if(st.empty()){
            S.push_back(i+1);
        }
        else{
            S.push_back(i-st.top());
        }
		// Push this element to stack 
		st.push(i); 
	  } 
	  return S;
    }

