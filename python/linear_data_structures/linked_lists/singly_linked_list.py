class node():
    def __init__(self, link, value):
        self.link = link;
        self.value = value;

def push(head, value):
    new_node = node(head, value)
    return new_node
 
def pop(head):
    if(head != None):
        return node(head.link.link, head.link.value)

def print_sll(head):
    cursor = head
    while(cursor != None):
        print(cursor.value)
        cursor = cursor.link

def main():
    head = node(None, 0)
    for i in range(1,5):
        head = push(head, i)
    print_sll(head)

if __name__ == "__main__":
    main()
