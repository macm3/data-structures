//pseudocode

//DFS
void search(Node root){
    if(root == null) return;
    visit(root);
    root.visited = true;
    for (Node n : root.adjacent){
        if(n.visited == false){
            search(n);
        }
    }
}

//BFS
void search(Node root){
    Queue queue = new Queue();
    root.marked = true;
    queue.enqueue(root); //add no final da lista
    
    while(!queue.isEmpty()){
        Node r = queue.dequeue(); //removendo do primeiro lugar da fila
        visit(r);
        for (Node n : r.adjacent) {
            if(n.marked == false){
                n.marked = true;
                queue.enqueue(n);
            }
        }
    }
}