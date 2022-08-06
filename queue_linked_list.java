class Node{
    int data;
    Node next;
    Node(int d){
        data=d;
    }
}
class Queue{
    Node front,rear;

    int enqueue(int data){
        Node newNode=new Node(data);
        if(front==null){
            front=rear=newNode;
            return 0;
        }
        rear.next=newNode;
        rear=newNode;
        return 0;
    }

    int dequeue(){
        if(front==null){
            System.out.println("No node in list");
            return 0;
        }
        int res=front.data;
        front=front.next;
        return res;
    }
}


public class queue_linked_list {
    public static void main(String[] args) {
        Queue in=new Queue();
        in.enqueue(10);
        in.enqueue(20);
        
        System.out.println("Dequeue is "+in.dequeue());
    }
    
}
