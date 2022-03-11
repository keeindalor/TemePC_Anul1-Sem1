#include "hunt.h"
#include <stdio.h>
#include <assert.h>

uint8_t get_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint8_t res = -1;

    /* TODO
     *
     * "res" should be 1 if the bit is active, else 0
     */
     
     nr = nr >> i;
     
     res = nr & 1;

    return res;
}
/* Task 1 - Axii */

uint16_t find_spell(uint64_t memory)
{
    /*
     * The spell is 16 bits and they are in the memory exactly after 5
     * consecutive bits of 1:
     *
     *            high                                             low
     *                [][][x]...[x][x][x][1][1][1][1][1][]...[][][]
     *                    |----16bits---|
     *                          Spell
     *
     * There is only 1 group of 5 consecutive bits of 1 and the other groups
     * have less than consecutive bits of 1
     * Steps:
     * - find 5 consecutive bits of 1
     * - the NEXT 16 bits == spell
     */

    uint16_t res = -1;

    /* TODO */
    
    uint64_t i, c=0, poz=0, spell = 0, poz_bit = 0, bit, j = 0;
    
    for ( i = 1; i < 64; i ++)
    {	 
    	if( (get_bit(memory, i) == 1 ) && (get_bit(memory, i-1) == 1))
    		c = c + 1;
    	else
    		c = 0;
    	if ( c == 4 )
    		{
    		poz = i;
    		break;
    		}
    }
    
    for (i = poz + 1 ; i < poz + 17; i ++)
    {
    	bit = get_bit (memory, i);
    	poz_bit = bit << j;
    	j = j+1;
    	spell = spell + poz_bit;
    }
    	
	res = spell;
	
    return res;
}


uint16_t find_key(uint64_t memory)
{
    /*
     * The key is 16 bits and they are in the memory exactly before 3
     * consecutive bits of 1:
     *
     *                high                                           low
     *                     [][][][1][1][1][x][x]...[x][x][]...[][][]
     *                                    |----16bits---|
     *                                           Key
     * Steps:
     * - find 3 consecutive bits of 1
     * - the PREVIOUS 16 bits == key
     */

    uint16_t res = -1;

    /* TODO */
    
    uint16_t i, poz = 0, key = 0, c = 0, bit = 0, poz_bit = 0, j = 0;
    
    for ( i = 17; i < 64; i ++ )
    {
    	if ( (get_bit (memory, i) == 1) && (get_bit (memory, i-1) == 1) )
    		c = c + 1;
    	else
    		c = 0;
    		
    	if ( c == 2 )
    	{
    		poz = i;
    		break;
    	}
    }
    
    for (i = poz - 18; i < poz - 2; i ++)
    {
    	bit = get_bit (memory, i);
    	poz_bit = bit << j;
    	key = key + poz_bit;
    	j++;
    }

    	res = key;
    	
    return res;
}


uint16_t decrypt_spell(uint16_t spell, uint16_t key)
{
    /*
     * Find the spell knowing that
     * spell_encrypted = spell_plaintext ^ key
     */

    uint16_t res = -1;

    /* TODO */
    
    uint16_t spell_decrypted;
    
    spell_decrypted = spell ^ key;
    res = spell_decrypted;

    return res;
}


/* Task 2 - Sword Play */

uint32_t choose_sword(uint16_t enemy)
{
    /*
     * Help Geralt construct a sword that will give him an advantage in battle.
     * The steps we will follow:
     * - choose the corect sword
     * - brand the sword with the correct runes such that the equation
     * for that specific enemy type is true
     *
     * How does the sword look (Sword template):
     *  [][][][] [0][0][0]...[0][0][0] [][][][][][][][][][][][][][][][]
     *  -------- --------------------- --------------------------------
     *     Type    Does not matter      The "Value" such that the equation
     *                               from 2 holds depending on the enemy type
     *    4 bits      12 bits                     16 bits
     *
     * 1. Type of the sword:
     * - 1001 - Silver Sword - for monsters
     * - 0110 - Steel Sword - for humans
     *
     *  If the number of active bits from variable "enemy" is even == Monster
     *  else == Human
     *
     * 2.
     * Monster Equation:
     *    Value ^ (Enemy & (1 - Enemy)) = 0
     *
     * Human Equation:
     *    Value + Enemy = 0
     */

    uint32_t res = -1;

    /* TODO */
    
    uint32_t sword_human = 0, sword_monster = 0, i, human_type, monster_type, c = 0;
    uint16_t value_human, value_monster;
    
    value_human = -enemy;
    
    value_monster = (enemy & (1 - enemy));
    
    human_type = 6;
    monster_type = 9;
    
    human_type = human_type << 28;
    monster_type = monster_type << 28;
    
    sword_human = value_human + human_type;
    sword_monster = value_monster + monster_type;
   
    
    for (i = 0; i < 16; i ++)
    {
    	if (get_bit (enemy, i) == 1)
    		c = c + 1;
    }
    
    if (c % 2 == 0)
    	res = sword_monster;
    	
    else
    	res = sword_human;

    return res;
}


/* Task 3 - The Witcher Trials */

uint32_t trial_of_the_grasses(uint16_t cocktail)
{
    /*
     * To become a witcher one must survive a cocktail of different
     * herbs. The body should generate the correct antibodies to
     * neutralize the given cocktail.
     *
     *
     * The antibodies need to respect the following properties:
     *   (antibodies_high & cocktail) ^ (antibodies_low | cocktail) = 0
     *   antibodies_low & antibodies_high = 0
     *   antibodies_low | antibodies_high = cocktail
     *
     * Where:
     *  [][][]...[][][] | [][][]...[][][]
     *  ---------------   ---------------
     *  antibodies_high    antibodies_low
     *      16 bits           16 bits
     *      -------------------------
     *              antibodies
     */
 
    uint32_t res = -1;

    /* TODO */
   
    uint32_t antibodies_high = 0, antibodies_low = 0, antibodies = 0;
    
   antibodies_high = cocktail;
   antibodies = antibodies_low | antibodies_high;
   res = antibodies << 16;

    return res;
}


uint8_t trial_of_forrest_eyes(uint64_t map)
{
    /*
     * For the next trail, the candidate is tied up and blindfolded.
     * They are also taken to a forest and they should return until
     * the next morning.
     *
     * The candidate knows that there are 4 possibilities for the forest:
     * Brokilon, Hindar, Wolven Glade and Caed Dhu.
     *
     * The candidate also knows those forests by heart, but first you
     * need to identify the forest.
     *
     * The characteristics for 3 of the forests are as follows:
     * - Brokilon - has ONLY groups of 4 trees (or a forest without any tree)
     *   Ex: a group of 4 trees: "...00111100..."
     * - Hindar - has ONLY 2 trees in the MIDDLE
     * - Wolven Glade - FULL of trees
     *
     * The "map" variable encodes the following information:
     * - 1 tree
     * - 0 patch of grass
     *
     * You should put in the "res" variable the index for the identified
     * forrest.
     * - Brokilon - index 0
     * - Hindar - index 1
     * - Wolven Glade - index 2
     * - Caed Dhu - index 3
     */

    uint8_t res = -1;

    /* TODO */

	res = 3;
	
	if (map == 0)
		
		res = 0;
		
		
	if (map == ((uint64_t)-1))
		
		res = 2;
		
		
	uint64_t i, c = 0, ok = 1;
	
	if ((get_bit (map, 31) == 1) && (get_bit (map, 32) == 1))
	{ res = 1;
	return res;
	}
		
	c = 0;
		
	for ( i = 0; i < 64; i ++)
	{
		if (get_bit(map, i) == 1)
			 c = c+1;
		else if ((c != 4) && (c != 0))
		{
			ok = 0;
			break;
		}
		     else
		     	c = 0;
		     
	}
	
	if ( ok == 1)
	{
	res = 0;
	
	}
	


	return res;
		
		
	
	
}


uint8_t trial_of_the_dreams(uint32_t map)
{
    /*
     * For this final trial, the candidates go into a trance and when
     * they woke up they would be a fully fledged witcher.
     *
     * For this task, you need to help the witcher find the number
     * of steps that would take the candidate from the dream realm to
     * the real world.
     *
     * The "map" variable would have only 2 bits of 1:
     * - candidate location
     * - portal location
     *
     * You should put in the "res" variable the distance from the
     * candidate position to the portal.
     *
     *  Ex:
     *  [0][0][0][0][0][0]....[1][0][0][0][0][1][0]....[0][0][0]
     *
     *  res = 5
     */

    uint8_t res = -1;

    /* TODO */
    
    uint8_t distance, poz1, poz2, i;
    
    for ( i = 0; i < 32; i ++)
    {
    	if (get_bit(map, i) == 1)
    	{
    		poz1 = poz2;
    		poz2 = i;
    	}
    }
    
    distance = poz2 - poz1;
    res = distance;

    return res;
}
