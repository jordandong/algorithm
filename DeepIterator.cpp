/*
 *
 *"Program an iterator for a List which may include nodes or List  i.e.  * {0, {1,2}, 3 ,{4,{5, 6}}} Iterator returns 0 - 1 - 2 - 3 - 4 - 5 - 6"
 *
 */
 
struct Node{
	int data;
	bool hasData;
	Node* nest;
	Node* next;
}

public class DeepInterator {
	private:
		stack<Node*> stk;
	public;
		DeepInterator(Node* node){
			stk.push(node);
			preNext();
		}

		bool hasNext() {
			return !stk.empty();
		}

		int next(){
			if(!hasNext()){
				return MIN_INT;
			}
			Node* t = stk.top();
			stk.pop();
			preNext();
			return t->data;
		}

		void preNext(){
			while(!stk.empty() && (stk.top()->nest || stk.top()->next)){
				stack<Node*> t_stk;
				Node* t = stk.top();
				stk.pop();
				if(t->hasData){
					t_stk.push(t);
				}
				if(t->nest){
					t_stk.push(t->nest);
					t->nest = NULL;
				}
				if(t->next){
					t_stk.push(t->next);
					t->next = NULL;
				}
				while(!t_stk.empty()){
					stk.push(t_stk.top());
					t_stk.pop();
				}
			}

		}
}



public class DeepIterator {

    private Stack<Object> stack;

    public DeepIterator(List<Object> list) {
        stack = new Stack<Object>();
        stack.push(list);
        advanceToNext();
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }

    public int next() {
        if (!hasNext())
            throw new RuntimeException("no next");

        int result = (Integer) stack.pop();
        advanceToNext();
        
        return result;
    }

    @SuppressWarnings("unchecked")
    private void advanceToNext() {
        while (!stack.isEmpty() && !(stack.peek() instanceof Integer)) {
            Object obj = stack.pop();
            if (obj == null)
                continue;

            List<Object> cur = (List<Object>) obj;

            for (int i = cur.size() - 1; i >= 0; i--)
                stack.push(cur.get(i));
        }
    }
}
