#include "image_node.h"
#include <core/type_manager.h>
#include <color/color_t.h>
#include <real/real_t.h>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Shared_Image.H>

Image_Node::Image_Node(const char* filename): Node(2){
	if(filename)
		set_image(filename);
	cache= new Color_t;
}
Image_Node::~Image_Node(){
	delete cache;
	if(image) image->release();
}
void Image_Node::set_image(const char* filename){
	if(image) image->release();
	image= Fl_Shared_Image::get(filename);
	if(!image)
		image= Fl_Shared_Image::get(new Fl_BMP_Image(filename));
}
Node* Image_Node::make(void* ptr){return new Image_Node((const char*)ptr);}

static Fl_Image* current_image;
void Image_Node::get_pixel(Node** nodes, void* ptr){
	static unsigned int x,y,d;
	d= current_image->d();
	x=((Real_t*)nodes[0]->cache)->value * current_image->w();
	y=((Real_t*)nodes[1]->cache)->value * current_image->h();
	switch(d){
		case 0:
			break;
		case 1:
			((Color_t*)ptr)->r=
			((Color_t*)ptr)->g=
			((Color_t*)ptr)->b=current_image->data()[0][(x+y*current_image->w())]/3.;
			((Color_t*)ptr)->a= 1;
			break;
		case 4:
			((Color_t*)ptr)->a= current_image->data()[0][(x+y*current_image->w())*4+3]/255.0;
			//fallthrough
		case 3:
			((Color_t*)ptr)->r= current_image->data()[0][(x+y*current_image->w())*d+0]/255.0;
			((Color_t*)ptr)->g= current_image->data()[0][(x+y*current_image->w())*d+1]/255.0;
			((Color_t*)ptr)->b= current_image->data()[0][(x+y*current_image->w())*d+2]/255.0;
			break;
		default: break;
	}
}

void Image_Node::update_cache(){
	current_image= image;
	main_func(inodes.data(), cache);
}
void Image_Node::update_types(){
	main_func= get_func("get_pixel", {inodes[0]->cache->id, inodes[1]->cache->id});
}
