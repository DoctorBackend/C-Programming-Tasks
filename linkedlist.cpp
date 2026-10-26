#include <iostream>
#include <cstring>
using namespace std ;


struct Node;

typedef Node *Node_Ptr;
struct Node
{
  char word[20];
  Node_Ptr ptr_to_next_node;
};

void assign_new_node(Node_Ptr &a_list)
{
  a_list = new Node;
  a_list->ptr_to_next_node=nullptr;

}

void assign_list(Node_Ptr &a_list)
{

  Node_Ptr current_node , last_node;

  assign_new_node(a_list);
  cout<<"Enter the first word ( or '.' to end list):";
  cin>>a_list->word;
  if(!strcmp(a_list->word ,"."))
    {
      delete a_list;
      a_list=nullptr;
    }
  current_node = a_list;

  while(current_node!=nullptr)
    {

      assign_new_node(last_node);

      cout<<"Enter the next word ( or '.' to end list): ";
      cin>> last_node->word;
      if (!strcmp(".",last_node->word))
        {
          delete last_node;
          last_node=nullptr;
        }
      current_node->ptr_to_next_node=last_node;
      current_node=last_node;
    }

}

void print_list(Node_Ptr a_list)
{
  while(a_list!=nullptr)
    {
      cout<<a_list->word<<endl;
      a_list=a_list->ptr_to_next_node;
    }
}
void add_after(Node_Ptr &a_list , char a_word[] , char word_after[])
{
  Node_Ptr current_node = a_list;
  Node_Ptr new_node = nullptr;
  if(a_list!=nullptr)
    {
      if(!strcmp(current_node->word,a_word))
        {
          assign_new_node(new_node);
          strcpy(new_node->word,word_after);
          new_node->ptr_to_next_node=current_node->ptr_to_next_node;
          current_node->ptr_to_next_node=new_node;
        }
      else
        {
          current_node=current_node->ptr_to_next_node;
          add_after(current_node,a_word,word_after);
        }
    }

}

void delete_node(Node_Ptr &a_list , char a_word[])
{
  Node_Ptr current = a_list ;
  Node_Ptr node_before = nullptr;
  while(current!=nullptr && strcmp(current->word,a_word))
    {
      node_before=current;
      current=current->ptr_to_next_node;
    }
  if(current!=nullptr)
    {

      if(node_before==nullptr)
        {
          node_before=current->ptr_to_next_node;
          a_list=node_before;
        }
      else
        {
          node_before->ptr_to_next_node=current->ptr_to_next_node;
        }

      delete current;
    }

}
bool string_comparer(char *p1, char *p2)
{
  while(*p2!='\0')
    {
      if(*p2>*p1)
      {
          return true;
      }
      else if(*p2<*p1)
      {
          return false;
      }
      else
      {
        p2++;
        p1++;
        if(*p1=='\0' && *p2!='\0')
          {
            return true;
          }
      }
    }
  return false;
}

Node_Ptr minimum_from(Node_Ptr &current_node , Node_Ptr &a_list)
{
  Node_Ptr next_node =current_node->ptr_to_next_node;
  char min_word[20];
  strcpy(min_word,current_node->word);
  while(next_node!=nullptr)
  {
    if(!string_comparer(min_word,next_node->word))
    {
       strcpy(min_word,next_node->word);
    }
    next_node=next_node->ptr_to_next_node;
  }
  if(strcmp(min_word,current_node->word))
    {
      Node_Ptr node=current_node;
       while(strcmp(node->word,min_word))
       {
          node=node->ptr_to_next_node;
       }
          return node;
    }
    return nullptr;
}


    void swap(Node_Ptr& first, Node_Ptr& second)
    {
      char temp[20] ;
      strcpy(temp,first->word);
      strcpy(first->word,second->word);
      strcpy(second->word,temp);
    }


void selection_sort(Node_Ptr &a_list)
    {
      Node_Ptr current_node =a_list;
      while(current_node!=nullptr)
          {
            Node_Ptr swap_pointer =minimum_from(current_node, a_list);
            if(swap_pointer!=nullptr)
              {
                swap(current_node,swap_pointer);
              }
            current_node=current_node->ptr_to_next_node;
          }
    }



int main()
{

  Node_Ptr a_list =nullptr;

  assign_list(a_list);
  cout<<"Current linked list : "<<endl;
  print_list(a_list);

  char first[]= "Hello";
  char second[]="Hi";

  add_after(a_list,first,second);

  cout<<"Edited linked list : "<<endl;
  print_list(a_list);
  cout<<endl;

  selection_sort(a_list);
  cout << "Sorted linked list:" << endl;
  print_list(a_list);

}
