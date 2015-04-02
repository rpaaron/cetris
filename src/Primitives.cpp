/* 
 * File:   Primitives.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 17.31
 */

#include "Primitives.h"


void drawColoredCube(float l, COLOR col) {
    
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE); 
    glLineWidth(2.5);
    
    glColor4f(col.r, col.g, col.b, col.a);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE); 
     
    glPolygonMode(GL_BACK, GL_FILL);
    drawCube(l);
    
    glColorMaterial(GL_FRONT, GL_EMISSION);
    glColor4f(0, 0, 0, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    drawCube(l);
}


void drawCube(float l) {
	 
 
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	  // Top face (y = 1.0f)
	  // Define vertices in counter-clockwise (CCW) order with normal pointing out
	     
          
	  glVertex3f( l, l, -l);
	  glVertex3f(-l, l, -l);
	  glVertex3f(-l, l,  l);
	  glVertex3f( l, l,  l);
 
	  // Bottom face (y = -1.0f)
	  glVertex3f( l, -l,  l);
	  glVertex3f(-l, -l,  l);
	  glVertex3f(-l, -l, -l);
	  glVertex3f( l, -l, -l);
 
	  // Front face  (z = 1.0f)
	  glVertex3f( l,  l, l);
	  glVertex3f(-l,  l, l);
	  glVertex3f(-l, -l, l);
	  glVertex3f( l, -l, l);
 
	  // Back face (z = -1.0f)
	  glVertex3f( l, -l, -l);
	  glVertex3f(-l, -l, -l);
	  glVertex3f(-l,  l, -l);
	  glVertex3f( l,  l, -l);
 
	  // Left face (x = -1.0f)
	  glVertex3f(-l,  l,  l);
	  glVertex3f(-l,  l, -l);
	  glVertex3f(-l, -l, -l);
	  glVertex3f(-l, -l,  l);
 
	  // Right face (x = 1.0f)
	  glVertex3f(l,  l, -l);
	  glVertex3f(l,  l,  l);
	  glVertex3f(l, -l,  l);
	  glVertex3f(l, -l, -l);
	glEnd();  // End of drawing color-cube

}
