public class StackExample {
  
    public static void main( String args[] ) {
	Stack stack = new Stack( );
      
	System.out.print( stack.isEmpty( ) );
	      
	stack.push(17);
	stack.push(" = ");
	stack.push(5);
	stack.push(" * ");
	stack.push(3);
	stack.push(" + ");
	stack.push(2);
	 
	System.out.print( stack.isEmpty( ) );
	
	while( !stack.isEmpty() )
	    System.out.print( stack.pop( ) );
      
	System.out.print( stack.isEmpty( ) );
  }
}

public class Stack {
   
    public Stack( ) {
        topOfStack = null;
    }
        
    public boolean isEmpty( ) {
        return topOfStack == null;
    }
    
    public void clear( ) {
        topOfStack = null;
    }
   
    public void push( Object x ) {
        topOfStack = new Node( x, topOfStack );
    }
    
    public void pop( ) {
        //	TO DO
	//	if( isEmpty() )
        //	throw StackException

	if( !isEmpty() )
        topOfStack = topOfStack.next;
    }
    
    public Object top( ) {
        //	TO DO
	//	if( isEmpty() )
        //	throw StackException

	if( !isEmpty( ) )
            return topOfStack.element;
    }
    
    private Node topOfStack;
}

class Node {
    
    public Node( Object newElement, Node newNext ) {
        element = newElement;
        next = newNext;
    }
    
    public Object element;
    public Node next;
}
