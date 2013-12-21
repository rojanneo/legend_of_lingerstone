
/*
	
	$tree_try.h

	Copyright (C) $2012 Anurag Prasad Pradhan, Iksha Gurung, Raj Kumar Thapa, Rojan Shrestha, Saugat Acharya
	
	This file is part of Calendar.
	
	The Legend of LingerStone is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Legend of LingerStone is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with The Legend of LingerStone.  If not, see <http://www.gnu.org/licenses/>.

	rojan_neo@hotmail.com
*/

#include<iostream>
#include<vector>
#include<string>
#define MAX 2//one parent can have only 4 child tops.
#define MAX_GEN 3//maximum generation of the entire tree...


using namespace std;
static int ID;
class node{
      private:
      int node_id;
      int parent_ID;
      string action;
      int child_no;
      int child_ID[2];
      bool leaf;
   
      public: 
              node();
              void add_child(node *);
              void set_parent_id(int );
              int get_node_id();
              void set_leaf(bool );
              bool is_leaf();
              string get_action();
              int set_id();
              int* get_child_ids();
              void set_id(int );
              int get_parent_id();
              void delete_child(node *);
              int find(node *);
              void set_string(string );
              int Get_ID();
              int get_child_no();
			  void reset_id();
};
             
              
