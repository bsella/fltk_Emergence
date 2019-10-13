#include "image_node.h"
#include <core/type_manager.h>
#include <color/color_t.h>
#include <real/real_t.h>
#include <FL/Fl_BMP_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <istream>

Image_Node::Image_Node(std::istream* str): Node(2){
	if(str){
		size_t len;
		str->read(reinterpret_cast<char*>(&len), sizeof(size_t));
		char* filename= new char[len];
		str->read(filename, len);
		set_image(filename);
		delete[] filename;
	}
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
Node* Image_Node::make(std::istream* str){
	return new Image_Node(str);
}
const char* Image_Node::id()const{return "image";}

static Fl_Image* current_image;
void Image_Node::get_pixel(Node** nodes, void* ptr){
	static unsigned int x,y,d;
	d= current_image->d();
	x=static_cast<Real_t*>(nodes[0]->cache)->value * current_image->w();
	y=static_cast<Real_t*>(nodes[1]->cache)->value * current_image->h();
	switch(d){
		case 0:
			break;
		case 1:
			static_cast<Color_t*>(ptr)->r=
			static_cast<Color_t*>(ptr)->g=
			static_cast<Color_t*>(ptr)->b=(((unsigned char)current_image->data()[0][(x+y*current_image->w())])/255)/3.;
			static_cast<Color_t*>(ptr)->a= 1;
			break;
		case 3:
			static_cast<Color_t*>(ptr)->r=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+0])/255.0;
			static_cast<Color_t*>(ptr)->g=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+1])/255.0;
			static_cast<Color_t*>(ptr)->b=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+2])/255.0;
			static_cast<Color_t*>(ptr)->a= 1;
			break;
		case 4:
			static_cast<Color_t*>(ptr)->r=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+0])/255.0;
			static_cast<Color_t*>(ptr)->g=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+1])/255.0;
			static_cast<Color_t*>(ptr)->b=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+2])/255.0;
			static_cast<Color_t*>(ptr)->a=((unsigned char)current_image->data()[0][(x+y*current_image->w())*d+3])/255.0;
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
	if(!main_func) main_func= &Color_t::rand;
}
