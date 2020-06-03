#include <binheap.h>
#include <string.h>
#include <stdio.h>

#define PARENT(pos) ((pos-1)/2) 
#define LEFT_CHILD(pos) (2*pos+1)
#define RIGHT_CHILD(pos) (2*pos+2)
#define VALID_NODE(H, node) (((H)->num_of_elem) > node) //An index for a node is valid if its smaller than the size of the heap
#define ADDR(H, node) ((H)->A+(node)*((H)->key_size)) //The position in memory where we want to go
#define INDEX_OF(H, addr) ((addr-((H)->A))/((H)->key_size))
#define POS(node) (H->key_pos[node]) //Returns the position of node i
#define NODE(pos) (H->rev_pos[pos]) //Returns the node in position i

int is_heap_empty(const binheap_type *H)
{
    if(H->num_of_elem != 0)
        return 0;

    return 1;
}

const void *min_value(const binheap_type *H)
{
    if(is_heap_empty(H) != 1)
        return ADDR(H,0);   //The minimum in a heap is stored in the root

    return NULL;
}

//What we want to know is the actual node in order to swap them
void swap_keys(binheap_type *H, unsigned int n_a, unsigned int n_b)
{
    unsigned int pos_a = POS(n_a);
    unsigned int pos_b = POS(n_b);

    //Update position arrays
    unsigned int tmp = POS(n_a);
    POS(n_a) = POS(n_b);
    POS(n_b) = tmp;

    //Update nodes array
    NODE(pos_a) = n_b;
    NODE(pos_b) = n_a;

}

const void *extract_min(binheap_type *H)
{
    if (is_heap_empty(H))
        return NULL;

    //Swapping the root with the rightmost leaf
    swap_keys(H,NODE(0),NODE(H->num_of_elem - 1));
    H->num_of_elem--;

    heapify(H,NODE(0));

    //This returns the address of the node in last position
    return ADDR(H, NODE(H->num_of_elem));
}

//We want an actual node, not its position
void heapify(binheap_type *H, unsigned int node){

    unsigned int dst_node=node, child;
    unsigned int node_pos, child_pos;

    //find the minimum among node and its children.
    do{
        dst_node = node;
        node_pos = POS(node);

        child_pos = RIGHT_CHILD(node_pos);

        if (VALID_NODE(H,child_pos)){

            child = NODE(child_pos);

            if(H->leq(ADDR(H, child), ADDR(H, dst_node)))
                dst_node = child;
        }
                
        child_pos = LEFT_CHILD(node_pos);

        if (VALID_NODE(H,child_pos)){
             child = NODE(child_pos);

            if(H->leq(ADDR(H, child), ADDR(H, dst_node)))
                dst_node = child;
        }

        //If the minimum is not in node
        // swap the keys
        if(dst_node != node){
            swap_keys(H, dst_node, node);
        }

    } while( dst_node != node);
}

const void *find_the_max(void *A, const unsigned int num_of_elem,
                        const size_t key_size, total_order_type leq)
{
    if(num_of_elem == 0)
        return NULL;

    const void *max_value = A; //First cell of the array
    //For all the values in A starting from the second one, scan the array
    for(const void *addr=A+key_size; addr!=A+((num_of_elem-1)*key_size); addr+=key_size){

        //If addr > max_value
        if(!leq(addr, max_value)){
            max_value = addr;
        }
    }

    return max_value;
}

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
    binheap_type *H = (binheap_type *)malloc(sizeof(binheap_type));

    H->A = A;
    H->num_of_elem = num_of_elem;
    H->max_size = max_size;
    H->key_size = key_size;
    H->leq = leq;
    H->max_order_value = malloc(key_size);

    H->key_pos = (int*)malloc(max_size*sizeof(int));
    H->rev_pos = (int*)malloc(max_size*sizeof(int)); 

    for(unsigned int i = 0; i < max_size; ++i){
        H->key_pos[i] = i;
        H->rev_pos[i] = i;
    }

    if( num_of_elem == 0){
        return H;
    }

    //Get the maximum among A[:num_of_elem -1]
    // and store it in the max_order_value
    const void *value = find_the_max(A, num_of_elem, key_size,leq);

    memcpy(H->max_order_value, value, key_size);

    for(int i = num_of_elem/2; i >= 0; i--)
        heapify(H,NODE(i));


    //heapify(H,0);
    return H;
}

void delete_heap(binheap_type *H)
{
    free(H->max_order_value);
    free(H);
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    if(H->num_of_elem == 1)
        return NULL; //We are inserting the root

    unsigned int node_idx = INDEX_OF(H, node);
    unsigned int node_pos = POS(node_idx);

    if(!(H->leq(value, node)))
        return NULL;

    memcpy(node, value, H->key_size);

    unsigned int parent_idx = NODE(PARENT(node_pos));
    void *parent = ADDR(H, parent_idx);

    // while node != root and *parent > *node 
    while ((node_pos != 0) && (!H->leq(parent, node )))
    {
        swap_keys(H, parent_idx, node_idx);

        node_pos = POS(node_idx);
        unsigned int new_parent_pos = PARENT(node_pos);

        if(VALID_NODE(H,new_parent_pos)){
            parent_idx = NODE(new_parent_pos);
            parent = ADDR(H, parent_idx);
        } else
        {
            break;
        }
        

    }
    
    return NULL;
}

const void *insert_value(binheap_type *H, const void *value)
{
    if(H->max_size == H->num_of_elem){
        return NULL;
    }

    //If heap is empty or value is greater than max order value, then value becomes the max order value
    if(H->num_of_elem == 0 || !H->leq(value, H->max_order_value))
        memcpy(H->max_order_value, value, H->key_size);

    //Create a new node and copy the max order value into it
    unsigned int new_node_idx = NODE(H->num_of_elem);
    void *new_node_addr = ADDR(H, new_node_idx);
    memcpy(new_node_addr, H->max_order_value, H->key_size);
    H->num_of_elem++;
    return decrease_key(H, new_node_addr, value);

}


void print_heap(const binheap_type *H, 
                void (*key_printer)(const void *value))
{
    unsigned int next_level_node = 1; //Stores the index of the left-most node of the next level
    
    for( unsigned int node = 0; node < H->num_of_elem; ++node){
        if(node == next_level_node){
            printf("\n");
            next_level_node=LEFT_CHILD(node);
        } else {
            printf("\n");
        }

        key_printer(ADDR(H, NODE(node)));
    }

    printf("\n");

}