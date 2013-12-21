#include"tree_try.h"

node::node()
{
      child_no =0;
      parent_ID = 0;
      leaf = false;
      action = "not specified yet.";
}
void node::add_child(node *nd)
{
    
      if(child_no<MAX && this->Get_ID()!= nd->Get_ID())
      {
           child_ID[child_no] = nd->get_node_id();
           nd->set_parent_id(this->get_node_id());
           child_no++;
      }
                                     
}
bool node::is_leaf()
{
        return leaf;
}
void node::set_leaf(bool a)
{
     leaf = a;
}
void node::set_parent_id(int id)
{
     parent_ID = id;
}
int node::get_node_id()
{
     return node_id;
}
              
string node::get_action()
{
     return action;
}
int node::set_id()
{
     node_id = ++ID;
     return node_id;
}
void node::reset_id()
{
	ID = 0;
}
void node::set_id(int n_id)
{
     node_id = n_id;
}
int node::get_parent_id()
{
     return parent_ID;
}
void node::delete_child(node *nd)
{
     int i;
     i = this->find(nd);
     if(i == -1)
     {
         cout<<"the child does not belong to this node."<<endl;
     }
     else if(child_no!=0&&i!=Get_ID())
     {
         child_ID[i] = 0;
         nd->set_parent_id(0);
         child_no--;
     }
     else
     {
         cout<<"cannot delete a node with children."<<endl;
     }
}
int node::find(node *temp1)
{
     for(int i = 0;i<MAX;i++)
     {
         if(this->child_ID[i]==temp1->get_node_id())
         {
              return i;
         }
         else if(this->Get_ID()==temp1->Get_ID())
         {
              return this->Get_ID();
         }
                           
     }
     return -1;
}
void node::set_string(string str)
{
     action = str;
}
int node::Get_ID()
{
     return node_id;
}
int node::get_child_no()
{
    return child_no;
}
int* node::get_child_ids()
{
    return child_ID;
}
