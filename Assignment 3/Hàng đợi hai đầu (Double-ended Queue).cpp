//ADD
void addrear(int element){
if(rear == arr.length-1){
    return;
}
if(front ==-1){
    front =0;
    rear = 0;
    arr[0]=element;
    return;
}
rear++;
arr[rear]= element;
}
void addfront(int element){
if(front==0) return;
if(front==-1) { 
    front =0; 
    rear =0;
    arr[0]= element;
    return;
}
front --
arr[front]= element;
}

//DELETE
int deletefront(){
    if(front ==-1) return -1;
    if(front== rear){
        int temp1 = arr[front];
        front = -1;
        rear = -1;
        return temp1; 
    }
    int temp = arr[front];
}
return temp;
int deleterear(){
    if (rear==-1) return -1;
    if(front ==rear){
        int temp1=arr[rear];
        front = -1;
        rear =-1;
        return temp1;
    }
    int temp=arr[rear];
    rear--;
    return temp;
}
