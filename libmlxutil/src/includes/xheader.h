/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xheader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:28:43 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 19:50:37 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XHEADER_H
# define XHEADER_H
# if defined __linux__ || defined LINUX
#  define XK_MISCELLANY 0
#  define XK_LATIN1 0
#  include <X11/keysymdef.h>
#  define XK_A XK_aXK_a
#  define XK_B XK_b
#  define XK_C XK_c
#  define XK_D XK_d
#  define XK_E XK_e
#  define XK_F XK_f
#  define XK_G XK_g
#  define XK_H XK_h
#  define XK_I XK_i
#  define XK_J XK_j
#  define XK_K XK_k
#  define XK_L XK_l
#  define XK_M XK_m
#  define XK_N XK_n
#  define XK_O XK_o
#  define XK_P XK_p
#  define XK_Q XK_q
#  define XK_R XK_r
#  define XK_S XK_s
#  define XK_T XK_t
#  define XK_U XK_u
#  define XK_V XK_v
#  define XK_W XK_w
#  define XK_X XK_x
#  define XK_Y XK_y
#  define XK_Z XK_z
#  define XK_ESCAPE XK_Escape
# elif defined __APPLE__
#  define XK_A 0
#  define XK_S 1
#  define XK_D 2
#  define XK_F 3
#  define XK_G 5
#  define XK_H 4
#  define XK_J 38
#  define XK_K 40
#  define XK_L 37
#  define XK_Q 12
#  define XK_W 13
#  define XK_E 14
#  define XK_R 15
#  define XK_T 17
#  define XK_Y 16
#  define XK_U 32
#  define XK_I 34
#  define XK_O 31
#  define XK_P 35
#  define XK_Z 6
#  define XK_X 7
#  define XK_C 8
#  define XK_V 9
#  define XK_B 11
#  define XK_N 45
#  define XK_M 46
#  define XK_ESCAPE 53
#  define XK_PLUS 69
#  define XK_MINUS 78
#  define XK_SPACE 49
#  define XK_COMMA 43
#  define XK_PERIOD 47
#  define XK_SLASH 44
#  define XK_SEMICOLON 41
# else
#  error Cannot map keys

# endif
#endif
