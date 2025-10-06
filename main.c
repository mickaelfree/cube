/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickmart <mickmart@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:06:58 by mickmart          #+#    #+#             */
/*   Updated: 2025/10/01 19:14:14 by mickmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

#include <X11/keysym.h>
float px, py;
void handle_keyboard(unsigned char key, int x, int y) {
  if (key == 'a')
    px -= 10;
  if (key == 'd')
    px += 10;
  if (key == 'w')
    py -= 10;
  if (key == 's')
    py += 10;
  glutPostRedisplay();
}
void drawPlayer() {
  glColor3f(1, 1, 0);
  glPointSize(8);
  glBegin(GL_POINTS);
  glVertex2f(px, py);
  glEnd();
}
int mapX = 8, mapY = 8, mapS = 64;
int map[] = {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 1, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1,

};
void drawMap2d() {
  int xo, yo;
  int x, y;
  for (x = 0; x < mapX; x++) {
    for (y = 0; y < mapY; y++) {
      if (map[y * mapX + x] == 1)
        glColor3f(1, 1, 1);
      else
        glColor3f(0, 0, 0);
      xo = x * mapS;
      yo = y * mapS;
      glBegin(GL_QUADS);
      glVertex2f(xo, yo);
      glVertex2f(xo, yo + mapS);
      glVertex2f(xo + mapS, yo + mapS);
      glVertex2f(xo + mapS, yo);
      glEnd();
    }
  }
}
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawMap2d();
  drawPlayer();
  glutSwapBuffers();
}
void init() {
  glClearColor(0.3, 0.3, 0.3, 0.3);
  gluOrtho2D(0, 1024, 512, 0);
  px = 300;
  py = 300;
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(1024, 512);
  glutCreateWindow("Cub3D");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(handle_keyboard);
  glutMainLoop();
  return 0;
}
