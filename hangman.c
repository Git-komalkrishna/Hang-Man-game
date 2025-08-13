// code for HANG MAN game 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
int main()
{  const char *watermark = 
        " _    _          _   _  _____ __  __          _   _ \n"
        "| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |\n"
        "| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |\n"
        "|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |\n"
        "| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |\n"
        "|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|\n"

        "\n \n"
        "      Created by: komal \n"
        "      GitHub: github.com/irumos\n"
        "      Project: Hangman Game in C\n";

    printf("%s\n", watermark);

    char words[][150] = { // words for game is selected from this list randomly
        "apple", "banana", "cherry", "date", "elderberry",
        "fig", "grape", "honeydew", "kiwi", "lemon",
        "mango", "nectarine", "orange", "papaya", "quince",
        "raspberry", "strawberry", "tangerine", "ugli", "vanilla",
        "watermelon", "xigua", "yam", "zucchini", "apricot",
        "blueberry", "cantaloupe", "dragonfruit", "eggplant", "fennel",
        "guava", "huckleberry", "iceberg", "jackfruit", "kumquat",
        "lime", "mulberry", "nutmeg", "olive", "persimmon",
        "quinoa", "radish", "saffron", "turnip", "umbrella",
        "violet", "walnut", "xylophone", "yogurt", "zeppelin",
        "acorn", "biscuit", "cabbage", "daisy", "eagle",
        "flamingos", "giraffe", "hamster", "iguana", "jellyfish",
        "koala", "llama", "muffin", "nightingale", "octopus",
        "penguin", "quokka", "raccoon", "squirrel", "tiger",
        "unicorn", "vulture", "wombat", "xerus", "yak",
        "zebra", "almond", "basil", "cumin", "dill",
        "endive", "fennel", "ginger", "hazelnut", "iris",
        "jasmine", "kale", "lavender", "mint", "oregano",
        "parsley", "rosemary", "sage", "thyme", "basilisk",
        "chameleon", "dodo", "elephant", "falcon", "gorilla",
        "hippopotamus", "impala", "jaguar", "kangaroo", "leopard",
        "meerkat", "narwhal", "ocelot", "panther", "quetzal",
        "rhinoceros", "salamander", "toucan", "urchin", "vampire",
        "warthog", "x-ray", "yellowjacket", "zebu", "aardvark",
        "baboon", "cougar", "dingo", "emu", "fox",
        "gazelle", "hyena", "ibex", "jerboa", "kudu",
        "lynx", "marten", "newt", "otter", "puma",
        "quail", "redpanda", "serval", "tapir", "uakari",
        "vicuna", "weasel", "xantus", "yeti", "zorse",
        "abacus", "bicycle", "calculator", "dictionary", "eraser",
        "fountain", "globe", "headphones", "inkwell", "joystick",
        "keyboard", "laptop", "monitor", "notebook", "organizer",
        "pencil", "quill", "ruler", "scissors", "tablet",
        "umbrella", "violin", "whiteboard", "xylophone", "yacht",
        "zipper", "airplane", "boat", "car", "drone",
        "engine", "ferry", "glider", "helicopter", "jet",
        "kayak", "limousine", "motorcycle", "nautilus", "omnibus",
        "paddleboat", "quadcopter", "rocket", "submarine", "train",
        "unicycle", "van", "wagon", "xebec", "yurt",
        "zeppelin", "anchor", "buoy", "compass", "diving",
        "echo", "flare", "goggles", "harbor", "island",
        "jettison", "knots", "lighthouse", "marina", "navigation",
        "ocean", "port", "quay", "reef", "sail",
        "tide", "underwater", "vessel", "wave", "xtreme",
        "yachting", "zenith"
    };
    int num_words = sizeof(words) / sizeof(words[0]); //to calculate number of words in the given list
    srand(time(NULL)); //to take a random number
    int index = rand() % num_words; //to take a random index within the range of number of words in the list
  char word[15],temp[15],dumb[30];
  int i,notfound,flag,k=0,n,pin,l=0;
  for(i=0;words[index][i]!='\0';i++)  // word is assigned to game
  { word[i]=words[index][i];
	temp[i]='_';
  }
  n=i;
  char a,c,d;
  printf("\n\n\nWelcome to hang man game\n \n");
  printf("to start the game press enter key ");  //start the game
  scanf("%c",&c);
  printf("\nfind the word which has %d letters\nyou have 7 chances",n); //defining number of letters to the user
  while(1)
  { flag=0;
   	pin=0;
    notfound=1;
	printf("\nEnter only one letter you are guessing: "); //letting the user guess letters in the word which is selcted randomly
	scanf(" %c",&d);
	a= tolower(d); //to convert the user entered letter into lower case
	printf("\nYou entered the letter %c",a);
	if(a>='a'&&a<='z')//check if the user entered correct character
	{
	}
	else //executed if user entered character or number as an input
	{ printf("\ninvalid input");
	  continue;
	}
	for(i=0;i<n||dumb[i]!='\0';i++) //to find the letter user entered is already found by him or not
	{ if(a==temp[i]||a==dumb[i])
	  { if(a==dumb[i]) //if already entered the letter by user in past and not found
		{ printf("\nYou already entered this letter and not found\n");
		  printf("\nLetters you have entered and not found:   ");
		  for(i=0;dumb[i]!='\0';i++)
		   printf("%c ",dumb[i]);
		  pin=1;
		  printf("\n\nEnter another letter \n");
		  break;
		}
		else //if already entered the letter by user in past and found
		{ printf("\nYou already found this letter");
		  printf("\n\nSee here dumb ass: ");
	      for(i=0;i<n;i++)
	      { printf("%c",temp[i]); //if the letter is already found the letters which are found are printed
          }
          printf("\n\nEnter another letter");
		  pin=1;
		  break;
		} 
	  }
	}
	if(pin) //if already found that letter the process is gone back to the first of loop
	 continue;
	for(i=0;i<n;i++) //check if the letter entered by user is present in the word or not
	{ if(word[i]==a)
	  { printf("\n\nFound the letter %c at position %d",a,i+1);
		temp[i]=a;
		notfound=0;
	  }
	}
	if(!notfound) //if the letter entered by user is found in the word then this block is executed
	{ printf("\n\nLetters you guessed right are:  ");
	  for(i=0;i<n;i++)  //letters guessed by user are printed
	  { printf("%c",temp[i]);
      }
      printf("\n");
    }
    if(notfound) //if the letter entered by user is not found in the word then this block is executed
    { printf("\n\nNot found the letter %c\n",a);
	  k++;
	  dumb[l]=a;
	  l++;
	}
	if(k!=0&&notfound==1) //if letter is not found then chances left are shown using switch
	{ switch(k)
	  {  case 1: printf("\n 6 chances are left"); //head
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
                break;
         case 2: printf("\n 5 chances are left"); //head anf body
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
              printf("\n      ."); 
              printf("\n      .");               
              printf("\n      ."); 
              printf("\n      ."); 
              printf("\n      ."); 
              printf("\n      ."); 
              printf("\n      ."); 
              printf("\n      ."); 
              printf("\n      .");       
                break;
         case 3: printf("\n 4 chances are left"); // head, body and left hand
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
              printf("\n     ..");               
              printf("\n    . .");
              printf("\n   .  .");
              printf("\n  .   .");
              printf("\n .    .");
              printf("\n      .");
              printf("\n      .");
              printf("\n      .");
              printf("\n      .");
                break;
          case 4: printf("\n 3 chances are left"); // head, body, left hand and right hand
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
              printf("\n     ...");               
              printf("\n    . . .");
              printf("\n   .  .  .");
              printf("\n  .   .   .");
              printf("\n .    .    .");
              printf("\n      .");
              printf("\n      .");
              printf("\n      .");
              printf("\n      .");
                break;
          case 5: printf("\n 2 chances are left"); //head, body, left hand, right hand and  left leg
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
              printf("\n     ...");               
              printf("\n    . . .");
              printf("\n   .  .  .");
              printf("\n  .   .   .");
              printf("\n .    .    .");
              printf("\n      .");
              printf("\n     ..");
              printf("\n    . ");
              printf("\n   .  ");
              printf("\n  .   ");
              printf("\n .    ");
                break;          
           case 6: printf("\n 1 chance are left"); //head, body, left hand, right hand, left leg and right leg
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
              printf("\n     ...");               
              printf("\n    . . .");
              printf("\n   .  .  .");
              printf("\n  .   .   .");
              printf("\n .    .    .");
              printf("\n      .");
              printf("\n     ...");
              printf("\n    .   .");
              printf("\n   .     .");
              printf("\n  .       .");
              printf("\n .         .");
                break;        
          case 7: 
              printf("\n      ."); // whole body and hanging rope
              printf("\n      .");
              printf("\n      .");
              printf("\n      .");
              printf("\n      .");
              printf("\n    . . .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n.           .");
              printf("\n .         .");
              printf("\n  .       .");
              printf("\n    . . .");
              printf("\n     ...");               
              printf("\n    . . .");
              printf("\n   .  .  .");
              printf("\n  .   .   .");
              printf("\n .    .    .");
              printf("\n      .");
              printf("\n     ...");
              printf("\n    .   .");
              printf("\n   .     .");
              printf("\n  .       .");
              printf("\n .         .");
              printf("\n\n\nYou lost the game\n\n");
              printf("\nThe word is ");  //if user lost the game the word user failed to guess will be displayed
               for(i=0;i<n;i++)
	           { printf("%c",word[i]);
               }
              exit(1);
       default: printf("nothing");
                break;
     }
     printf("\n\nLetters you guessed right : "); //letters guessed correctly are shown if letter entered by user is not found
	  for(i=0;i<n;i++)
	  { printf("%c",temp[i]);
      }
      printf("\n");
    }
    for(i=0;i<n;i++) //checking if the user found all the letters of the word
    { if(temp[i]!=word[i])
	  { flag=1;
      }
    }
    if(flag==0) //if all letters are found by the user then game is won and program is terminated
    {
     printf("\n \n \nYou won the game\n\n");
     exit(1);
    }
  }
  return 0;
}
                     
                 
                
