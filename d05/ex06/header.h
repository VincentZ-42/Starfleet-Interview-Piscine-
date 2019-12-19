/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:34:44 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:35:42 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_people
{
	char *name; 
	int time; //in minute
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int isPossible(struct s_people **people, int nbTable, int totalTime);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_people **readGuestList();


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
