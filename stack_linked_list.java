class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
    }
}
class Mystack{
    Node head;
    public Mystack(){
        head=null;
    }
    void push(int data){
        Node temp=new Node(data);
        temp.next=head;
        head=temp;
    }
    int peek(){
        if(head==null){
            System.out.println("underflow");
        }
        return head.data;
    }
    int pop(){
        if(head==null){
            System.out.println("Underflow");
        }
        int res=head.data;
        head=head.next;
        return res;
    }
}

public class stack_linked_list {
    public static void main(String[] args) {
        Mystack stack=new Mystack();
        stack.push(10);
        stack.push(20);
        stack.pop();
        System.out.println("top element is "+stack.peek());
        
    }
    
}

    

