class node():
    def __init__(self, link, value):
        self.link = link;
        self.value = value;

def push(head, value):
    new_node = node(head, value)
    return new_node
 
def pop(head):
    if(head.link != None):
        return node(head.link.link, head.link.value)

def print_sll(head):
    cursor = head
    while(cursor != None):
        print(cursor.value)
        cursor = cursor.link

def search(head, value):
    index = 0
    while(head != None and head.value != value):
        index += 1
        head = head.link
    return index

def insert(head, value, index=0):
    i = 0
    cursor = head
    last = None
    if(head.link == None):
        return push(head, value)
    else:
        while(i < index and cursor != None):
            last = cursor
            cursor = cursor.link
            i += 1
        new_node = node(cursor,value)
        last.link = new_node
    return head

def delete(head, index):
    i = 0
    cursor = head
    last = None
    if(index == 0):
        return pop(head)
    else:
        while(i < index and cursor != None):
            last = cursor 
            cursor = cursor.link
            i += 1
        last.link = cursor.link 
    return head

def main():
    head = node(None, 0)
    for i in range(1,5):
        head = push(head, i)
    print_sll(head)
    head = insert(head,3,search(head, 3))
    print_sll(head)
    head = delete(head, 1)
    print_sll(head)


if __name__ == "__main__":
    main()
