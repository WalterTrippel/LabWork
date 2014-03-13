public class BST{

   private Node root;

   private class Node{
       private int key;
       private Node left, right;

       public Node(int key){
	  this.key = key;
       }
   }

   public void put(int key){
       root = put(root, key);
   }

   private Node put(Node x, int key){
       if(x == null ) return new Node(key);

       key < x.key ? x.left = put(x.left, key) : x.right = put(x.right, key);
   }  
   
   public boolean find(int key){
       return find(root, key);
   }

   private boolean find(Node x,int key)
   {
        if(x = null) return false;
       
        if(key < x.key)
	  return find(x.left, key);
        else if(key > x.key)
	  return find(x.right, key);
	else return true;
   } 

   public void delete(Key key){
      root = delete(root,key)
   }

   private Node delete(Node x,Key key){
      if(x == null) return null;
      
      if(key < x.key)
	x.left = delete(x.left, key);
      else if(key > x.key)
	x.right= delete(x.right, key);
      else {
          if(x.right == null) return x.left;
          if(x.left == null) return x.right;
          
          Node temp = x;
          x = min(temp.right);
          x.right = deleteMin(temp.right);
          x.left = temp.left;
      }
      return x;
   }
   
   private Node min(Node x){
       if(x.left == null) return x;
      
       return min(x.left);
   }
   
   private Node deleteMin(Node x){
      if(x.left == null) return x.right;
 
      x.left = deleteMin(x.left);
      return x;
   }

} 
