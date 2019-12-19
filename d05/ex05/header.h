/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzhao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 21:34:01 by vzhao             #+#    #+#             */
/*   Updated: 2019/12/11 21:34:02 by vzhao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void	printUniquePermutations(char *str);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// DICTIONNARY

struct s_item {
  char          *key;
  int           value;
  struct s_item *next;
};

struct s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
};

struct s_dict *dictInit(int capacity);
int dictInsert(struct s_dict *dict, char *key, int value); //return -1 if fail
int dictSearch(struct s_dict *dict, char *key);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
