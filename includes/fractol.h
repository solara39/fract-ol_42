/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skondo <skondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:37:12 by skondo            #+#    #+#             */
/*   Updated: 2024/05/04 12:58:55 by skondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"

# define SIZE 700
# define THREAD_WIDTH 7
# define THREAD_NUMBER 100

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_data {
  void  *mlx;
  void  *window;
  void  *image;
  void  *addr;
  int bits_per_pixel;
  int size_line;
  int endian;
  int color;
  int x;
  int y;
  double  r;
  double  i;
  double  c_r;
  double  c_i;
  double  x_offset;
  double  y_offset;
  char  *name;
  double  zoom;
  int iterations;
}t_data;

// main.c
int draw_fractol(t_data *fractol, char *argv);

// utils.c
void  put_color_to_pixel(t_data *fractol, int x, int y, int color);
int exit_fractol(t_data *fractol);
double  generate_constant();
void  change_iteration(t_data *fractol, int code);

// init.c
void  init_fractol(t_data *fractol);
void  init_mlx(t_data *fractol);

// mandelbrot.c
void  calculate_mandelbrot(t_data *fractol);

// julia.c
void  calculate_julia(t_data  *fractol);

// mouse_keys.c
void handle_zoom(t_data *fractol, int x, int y, int zoom);
int handle_key(int code, t_data *fractol);
int handle_mouse(int code, int x, int y, t_data *fractol);

// draw.c
void  draw_mandelbrot(t_data *fractol);
void  draw_julia(t_data *fractol);

#endif
