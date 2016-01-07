# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Mandelbrot.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 20:24:52 by jbyttner          #+#    #+#              #
#    Updated: 2016/01/07 20:56:15 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from sys import argv
import traceback

def mandelbrot(c, sample):
	if (sample == 0):
		return (c)
	return mandelbrot(c, sample - 1) ** 2 + c

if __name__ == "__main__":
	if len(argv) > 1:
		try:
			c = complex(argv[1])
			try:
				print(mandelbrot(c, 100), 100);
			except OverflowError:
				try:
					print(mandelbrot(c, 10), 10)
				except OverflowError:
					print(mandelbrot(c, 4), 4)
		except Exception as e:
			traceback.print_exc();
			exit(0)
