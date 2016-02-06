/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xheader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 19:28:43 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 13:21:27 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** http://www.opensource.apple.com/source/tcl/tcl-87/tk/tk/xlib/X11/X.h
*/

#ifndef XHEADER_H
# define XHEADER_H
# if defined __linux__ || defined LINUX
#  define XK_MISCELLANY 0
#  define XK_LATIN1 0
#  include <X11/keysymdef.h>
#  include <X11/X.h>
#  define XKC_A XK_a
#  define XKC_B XK_b
#  define XKC_C XK_c
#  define XKC_D XK_d
#  define XKC_E XK_e
#  define XKC_F XK_f
#  define XKC_G XK_g
#  define XKC_H XK_h
#  define XKC_I XK_i
#  define XKC_J XK_j
#  define XKC_K XK_k
#  define XKC_L XK_l
#  define XKC_M XK_m
#  define XKC_N XK_n
#  define XKC_O XK_o
#  define XKC_P XK_p
#  define XKC_Q XK_q
#  define XKC_R XK_r
#  define XKC_S XK_s
#  define XKC_T XK_t
#  define XKC_U XK_u
#  define XKC_V XK_v
#  define XKC_W XK_w
#  define XKC_X XK_x
#  define XKC_Y XK_y
#  define XKC_Z XK_z
#  define XKC_KP_ADD XK_KP_Add
#  define XKC_KP_SUBTRACT XK_KP_Subtract
#  define XKC_ESCAPE XK_Escape
# elif defined __APPLE__
#  define XKC_A 0
#  define XKC_S 1
#  define XKC_D 2
#  define XKC_F 3
#  define XKC_G 5
#  define XKC_H 4
#  define XKC_J 38
#  define XKC_K 40
#  define XKC_L 37
#  define XKC_Q 12
#  define XKC_W 13
#  define XKC_E 14
#  define XKC_R 15
#  define XKC_T 17
#  define XKC_Y 16
#  define XKC_U 32
#  define XKC_I 34
#  define XKC_O 31
#  define XKC_P 35
#  define XKC_Z 6
#  define XKC_X 7
#  define XKC_C 8
#  define XKC_V 9
#  define XKC_B 11
#  define XKC_N 45
#  define XKC_M 46
#  define XKC_ESCAPE 53
#  define XKC_KP_ADD 69
#  define XKC_KP_SUBTRACT 78
#  define XKC_SPACE 49
#  define XKC_COMMA 43
#  define XKC_PERIOD 47
#  define XKC_SLASH 44
#  define XKC_SEMICOLON 41
#  define XNOEVENTMASK 0L
#  define XKEYPRESSMASK (1L<<0)
#  define XKEYRELEASEMASK (1L<<1)
#  define XBUTTONPRESSMASK (1L<<2)
#  define XENTERWINDOWMASK (1L<<3)
#  define XLEAVEWINDOWMASK (1L<<4)
#  define XPOINTERMOTIONMASK (1L<<5)
#  define XMOTIONNOTIFY 6
# else
#  error Cannot map keys

# endif
#endif
