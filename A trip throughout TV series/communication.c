#include "communication.h"
#include "util_comm.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

/* Task 1 - The Beginning */

void send_byte_message(void)
{
    /* TODO
     * Send the encoding of the characters: R, I, C, K
     */
     
   send_squanch ('R' - 'A' +1 );
   send_squanch ('I' - 'A' +1 );
   send_squanch ('C' - 'A' +1 );
   send_squanch ('K' - 'A' +1 );
}


void recv_byte_message(void)
{
    /* TODO
     * Receive 5 encoded characters, decode them and print
     * them to the standard output (as characters)
     *
     * ATTENTION!: Use fprintf(stdout, ...)
     */
     char code[6];
     
     uint8_t i;
     
     for (i = 0; i < 5; i ++)
     
     	code[ i ] = recv_squanch () + 'A' - 1;
     	
     fprintf(stdout, "%s", code);
     	
   
     	
}


void comm_byte(void)
{
    /* TODO
     * Receive 10 encoded characters and send each character (the character is
     * still encoded) 2 times
     */
     
     char code [11];
     
     uint8_t i;
     
     for ( i = 0; i <= 9; i ++)
     
     {
     	code [ i ] = recv_squanch ();
     	
     	send_squanch(code [ i ]);
     	
     	send_squanch(code [ i ]);
     }
}


/* Task 2 - Waiting for the Message */

void send_message(void)
{
    /* TODO
     * Send the message: HELLOTHERE
     * - send the encoded length
     * - send each character encoded
     */
     char message [11] = "HELLOTHERE";
     char c;
     uint8_t i, lenght= 10;
     
     
     	lenght = lenght << 4;
    	lenght = lenght >> 2;
     
     send_squanch(lenght);
     
     for ( i = 0; i <= 9; i ++)
     		{c = message [i] - 'A' + 1;
     		
     		send_squanch(c);
     		}
     
     

     
}


void recv_message(void)
{
    /* TODO
     * Receive a message:
     * - the first value is the encoded length
     * - length x encoded characters
     * - print each decoded character
     * 
     * ATTENTION!: Use fprintf(stdout, ...)
     */
     char message [11];
     uint8_t i, length ;
     
     
     length = recv_squanch();
     
     length = length << 2;
     length = length >> 4;
     
   
     
     for ( i = 0; i < length; i ++ )
        
        {
        message [ i ] = recv_squanch() + 'A' - 1;
        
       
        
        }
        
        
        
          fprintf(stdout, "%d", length);
        
        fprintf(stdout, "%s", message);
        
     
        
      
}


void comm_message(void)
{
    /* TODO
     * Receive a message from Rick and do one of the following depending on the
     * last character from the message:
     * - 'P' - send back PICKLERICK
     * - anything else - send back VINDICATORS
     * You need to send the messages as you did at the previous tasks:
     * - encode the length and send it
     * - encode each character and send them
     */
     
     char message [15], msg1 [10] = "PICKLERICK", msg2 [11] = "VINDICATORS";
     uint8_t length1 = 10, length2 = 11, length, i;
     
     length = recv_squanch();
     length = length << 2;
     length = length >> 4;
     
     for ( i = 0; i < length; i ++)
     	message [i] = recv_squanch() + 'A' - 1;
     
     if (message [length - 1] == 'P')
     	{
     		length1 = length1 << 4;
     		length1 = length1 >> 2;
     		send_squanch (length1);
     		
     		for (i = 0; i <= 9; i ++)
     			send_squanch(msg1 [i] - 'A' + 1);
     			
     	}
     	
     else
     	{
     		length2 = length2 << 4;
     		length2 = length2 >> 2;
     		send_squanch (length2);
     		
     		for ( i = 0; i <= 10; i ++)
     			send_squanch(msg2 [i] - 'A' + 1);
     	
     	}
     
     
    
     
     
}

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

/* Task 3 - In the Zone */

void send_squanch2(uint8_t c1, uint8_t c2)
{
    /* TODO
     * Steps:
     * - "merge" the character encoded in c1 and the character encoded in c2
     * - use send_squanch to send the newly formed byte
     */
     
     uint8_t code = 0, i, b1, b2, poz1, poz2;
     
     for (i = 0; i < 4; i ++)
     { b1 = get_bit (c1, i);
       b2 = get_bit (c2, i);
      
      
       poz2 = b2 << (i*2);
       poz1 = b1 << (i*2+1); 
       
       
       code = code + poz1+poz2;
       
	
      }
      
      send_squanch (code);
       
     	
}


uint8_t decode_squanch2(uint8_t c)
{
    /*
     * Decode the given byte:
     * - split the two characters as in the image from ocw.cs.pub.ro
     */

    uint8_t res = -1;

    /* TODO */
    
	uint8_t i, b1, b2, code = 0, poz1, poz2;
	
	for (i = 0; i < 4; i ++)
	{
		b1 = get_bit (c, i*2);
		b2 = get_bit (c, i*2+1);
		
		poz1 = b1 << i;
		poz2 = b2 << (i+4);
		
		code = code + poz1 + poz2;
		
	}
	
	res = code;

    return res;
}
