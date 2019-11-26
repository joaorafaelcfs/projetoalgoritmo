#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int entrada, ent, sai, linhas, contador = 0, y, j, p, tabela[100][100], snot[100], snor[100], sand[100], sor[100], snand[100], sxor[100];
char texto[1000], input[6] = "INPUT", output[7] = "OUTPUT", and_[4] = "AND", not_[4] = "NOT", nor[4] = "NOR", or_[3] = "OR", xor_[4] = "XOR", nand[5] = "NAND";
int i, a, k, x, cont, tamanho, e_and, e_not, e_nor, e_or, e_nand , e_xor , s_nand, s_xor, s_nor, s_and, s_not , s_or, saida[20];
int pos, g;
struct entrada{
  int e[200][200];
  int IN[100];
};
struct saida{
  int OUT[100];
};
struct and_{
  int ent[100];
  int saida[100];
};
struct not_{
  int ent[100];
  int saida[100];
};
struct nor{
  int ent[100];
  int saida[100];
};
struct or_{
  int ent[100];
  int saida[100];
};
struct nand{
  int ent[100];
  int saida[100];
};struct xor_{
  int ent[100];
  int saida[100];
};

struct entrada IN;
struct saida OUT;
struct and_ st_and;
struct not_ st_not;
struct nor st_nor;
struct or_ st_or;
struct nor st_xor;
struct nor st_nand;

void entradas(){
  entrada = ent;
  linhas = pow (2, entrada);
  for(y = 0; y < linhas; y++){
    contador = y;
    for(j = 1; j <= entrada; j++){
      if(contador % 2 == 0 ){
        tabela[y][j] = 0;
        contador = contador / 2;
      } else{
        tabela[y][j] = 1;
        contador = contador / 2;
      }
    }
  }
  for (j = 1; j <= entrada; j++){
    for (y = 0; y < linhas; y++){ 
        IN.e[y][j] = tabela[y][j];     
    }
  }  
}
void exp_or(){
  entrada = e_or;
  for (k = 0; k<=e_or; k++){
    for (j = 1; j<=ent; j++){
      if (st_or.ent[k] == IN.IN[j]){
        pos++;
        for(y=0; y<linhas; y++){
          for (g = pos;g<=pos; g++){
            tabela[y][g] = IN.e[y][j];
          }
        }
      }      
    } for (j = 1; j<=s_nor; j++){
        if (st_or.ent[k] == st_nor.saida[j]){
          pos++; 
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snor[y];
            }
          }
      }      
    }
    for (j = 1; j<=s_and; j++){
      if (st_or.ent[k] == st_and.saida[j]){
        pos++; 
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sand[y];
            }
          }
        }      
    } for (j = 1; j<=s_not; j++){
        if (st_or.ent[k] == st_not.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snot[y];
            }
          }
        }      
      } for (j = 1; j<=s_nand; j++){
        if (st_or.ent[k] == st_nand.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snand[y];
            }
          }
        }      
      } for (j = 1; j<=s_or; j++){
        if (st_or.ent[k] == st_or.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sor[y];
            }
          }
        }      
      } for (j = 1; j<=s_xor; j++){
        if (st_or.ent[k] == st_xor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sxor[y];
            }
          }
        }      
      } 
    if (pos == e_or){
      pos = 0;
    }
  }
  entrada = e_or;
  cont = 0;
  for (k = 0; k<linhas; k++){    
    g = 1;
    while (g<=entrada){
      if (tabela[k][g] == 0){
        cont++;        
        if (cont == entrada){
          sor[k] = 0;
          cont = 0;
        }
      } else{
        sor[k] = 1;
        cont = 0;
      } 
    g++;
    }
  }
  for (k = 0; k<=s_or; k++){
    for (j = 1; j<=sai; j++){
      if (st_or.saida[k] == OUT.OUT[j]){
        for(y=0; y<linhas; y++){          
            saida[y] = sor[y];
        }
      }      
    }
  }
}
void exp_nand(){
entrada = e_and;
  for (k = 0; k<=e_nand; k++){
    for (j = 1; j<=ent; j++){
      if (st_nand.ent[k] == IN.IN[j]){
        pos++;
        for(y=0; y<linhas; y++){
          for (g = pos;g<=pos; g++){
            tabela[y][g] = IN.e[y][j];  
          }
        }
      }      
    } for (j = 1; j<=s_nor; j++){
        if (st_nand.ent[k] == st_nor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snor[y];
            }
          }
        }      
      } for (j = 1; j<=s_not; j++){
          if (st_nand.ent[k] == st_not.saida[j]){
            pos++;
            for(y=0; y<linhas; y++){
              for (g = pos;g<=pos; g++){
                tabela[y][g] = snot[y];
              }
            }
          }   
        } for (j = 1; j<=s_or; j++){
            if (st_nand.ent[k] == st_or.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sor[y];
                }
              }
            }   
          } for (j = 1; j<=s_and; j++){
            if (st_nand.ent[k] == st_and.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sand[y];
                }
              }
            }   
          } for (j = 1; j<=s_xor; j++){
            if (st_nand.ent[k] == st_xor.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sxor[y];
                }
              }
            }   
          }for (j = 1; j<=s_nand; j++){
            if (st_nand.ent[k] == st_nand.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = snand[y];
                }
              }
            }   
          }
    if (pos == e_nand){
      pos = 0;
    }
  }
  entrada = e_nand;
  cont = 0;
  for (k = 0; k<linhas; k++){
    g = 1;
    while (g<=entrada){
      if (tabela[k][g] == 1){
        cont++;        
        if (cont == entrada){
          snand[k] = 0;
          cont = 0;
        }        
      } else{
        snand[k] = 1;
        cont = 0;
      }
      g++;
    }
  }
  for (k = 0; k<=s_nand; k++){
    for (j = 1; j<=sai; j++){
      if (st_nand.saida[k] == OUT.OUT[j]){
        for(y=0; y<linhas; y++){          
            saida[y] = snand[y];
        }
      }      
    }
  }
}
void exp_xor(){
  entrada = e_xor;
  for (k = 0; k<=e_xor; k++){
    for (j = 1; j<=ent; j++){
      if (st_xor.ent[k] == IN.IN[j]){
        pos++;
        for(y=0; y<linhas; y++){
          for (g = pos;g<=pos; g++){
            tabela[y][g] = IN.e[y][j];
          }
        }
      }      
    } for (j = 1; j<=s_nor; j++){
        if (st_xor.ent[k] == st_nor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snor[y];
            }
          }
      }      
    }
    for (j = 1; j<=s_and; j++){
      if (st_xor.ent[k] == st_and.saida[j]){
        pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sand[y];
            }
          }
        }      
    } for (j = 1; j<=s_not; j++){
        if (st_xor.ent[k] == st_not.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snot[y];
            }
          }
        }      
      } for (j = 1; j<=s_nand; j++){
        if (st_xor.ent[k] == st_nand.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snand[y];
            }
          }
        }      
      } for (j = 1; j<=s_or; j++){
        if (st_xor.ent[k] == st_or.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sor[y];
            }
          }
        }      
      } for (j = 1; j<=s_xor; j++){
        if (st_xor.ent[k] == st_xor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sxor[y];
            }
          }
        }      
      } 
    if (pos == e_xor){
      pos = 0;
    }
  }
  entrada = e_xor;
  cont = 0;
  for (k = 0; k<linhas; k++){
    g = 1;
    while (g<=entrada){
      if (tabela[k][g] == 1){
        cont++;
        g++;
    } 
    } if (cont%2 == 1){
        sand[k] = 1;
        cont = 0;
      }else{
        sand[k] = 0;
        cont = 0;
      }
  }
  for (k = 0; k<=s_xor; k++){
    for (j = 1; j<=sai; j++){
      if (st_xor.saida[k] == OUT.OUT[j]){
        for(y=0; y<linhas; y++){          
            saida[y] = sxor[y];
        }
      }      
    }
  }
}
void exp_and(){
  entrada = e_and;
  for (k = 0; k<=e_and; k++){
    for (j = 1; j<=ent; j++){
      if (st_and.ent[k] == IN.IN[j]){
        pos++;
        for(y=0; y<linhas; y++){
          for (g = pos;g<=pos; g++){
            tabela[y][g] = IN.e[y][j];  
          }
        }
      }      
    } for (j = 1; j<=s_nor; j++){
        if (st_and.ent[k] == st_nor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snor[y];
            }
          }
        }      
      } for (j = 1; j<=s_not; j++){
          if (st_and.ent[k] == st_not.saida[j]){
            pos++;
            for(y=0; y<linhas; y++){
              for (g = pos;g<=pos; g++){
                tabela[y][g] = snot[y];
              }
            }
          }   
        } for (j = 1; j<=s_or; j++){
            if (st_and.ent[k] == st_or.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sor[y];
                }
              }
            }   
          } for (j = 1; j<=s_and; j++){
            if (st_and.ent[k] == st_and.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sand[y];
                }
              }
            }   
          } for (j = 1; j<=s_xor; j++){
            if (st_and.ent[k] == st_xor.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sxor[y];
                }
              }
            }   
          }for (j = 1; j<=s_nand; j++){
            if (st_and.ent[k] == st_nand.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = snand[y];
                }
              }
            }   
          }
    if (pos == e_and){
          pos = 0;
    }
  }
  entrada = e_and;
  cont = 0;
  for (k = 0; k<linhas; k++){
    g = 1;
    while (g<=entrada){
      if (tabela[k][g] == 1){
        cont++;        
        if (cont == entrada){
          sand[k] = 1;
          cont = 0;
        }        
      } else{
        sand[k] = 0;
        cont = 0;
      }
      g++;
    }
  }
  for (k = 0; k<=s_and; k++){
    for (j = 1; j<=sai; j++){
      if (st_and.saida[k] == OUT.OUT[j]){
        for(y=0; y<linhas; y++){          
            saida[y] = sand[y];
        }
      }      
    }
  }
}
void exp_not(){
  entrada = e_not;
  for (k = 0; k<=e_not; k++){
    for (j=1; j<=ent; j++){
      if(st_not.ent[k] == IN.IN[j]){   
        pos++;
        for(y=0; y<linhas; y++){
          for (g = pos;g<=pos; g++){
            tabela[y][g] = IN.e[y][j];
          }
        }            
      }
    } for (j = 1; j<=s_and; j++){
        if (st_not.ent[k] == st_and.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sand[y];
            }
          }
        }      
      } for (j = 1; j<=s_or; j++){
          if (st_not.ent[k] == st_or.saida[j]){
            pos++;
            for(y=0; y<linhas; y++){
              for (g = pos;g<=pos; g++){
                tabela[y][g] = sor[y];
              }
            }
          }      
        } for (j = 1; j<=s_xor; j++){
            if (st_not.ent[k] == st_xor.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = sxor[y];
                }
              }
            }      
          } for (j = 1; j<=s_nand; j++){
              if (st_not.ent[k] == st_nand.saida[j]){
              pos++;
              for(y=0; y<linhas; y++){
                for (g = pos;g<=pos; g++){
                  tabela[y][g] = snand[y];
                }
              }
            }      
          } for (j = 1; j<=s_not; j++){
              if (st_not.ent[k] == st_not.saida[j]){
                pos++;
                for(y=0; y<linhas; y++){
                  for (g = pos;g<=pos; g++){
                    tabela[y][g] = snot[y];
                  }
                }
              }      
          } for (j = 1; j<=s_nor; j++){
              if (st_not.ent[k] == st_nor.saida[j]){
                pos++;
                for(y=0; y<linhas; y++){
                  for (g = pos;g<=pos; g++){
                    tabela[y][g] = snor[y];
                  }
                }
              }      
            }
        if (pos == e_not){
          pos = 0;
        }    
  }
  g = 1;
  for (k = 0; k<linhas; k++){        
    if (tabela[k][g] == 1){
        snot[k] = 0;
    }else{
        snot[k] = 1;
    }  
  }
  for (k = 0; k<=s_not; k++){
    for (j = 1; j<=sai; j++){
      if (st_not.saida[k] == OUT.OUT[j]){
        for(y=0; y<linhas; y++){          
            saida[y] = snot[y];
        }
      }      
    }
  }

}
void exp_nor(){
  entrada = e_nor;
  for (k = 0; k<=e_nor; k++){
    for (j = 1; j<=ent; j++){
      if (st_nor.ent[k] == IN.IN[j]){
        pos++;
        for(y=0; y<linhas; y++){
          for (g = pos;g<=pos; g++){
            tabela[y][g] = IN.e[y][j];
          }
        }
      }      
    } for (j = 1; j<=s_nor; j++){
        if (st_nor.ent[k] == st_nor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snor[y];
            }
          }
      }      
    }
    for (j = 1; j<=s_and; j++){
      if (st_nor.ent[k] == st_and.saida[j]){
        pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sand[y];
            }
          }
        }      
    } for (j = 1; j<=s_not; j++){
        if (st_nor.ent[k] == st_not.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snot[y];
            }
          }
        }      
      } for (j = 1; j<=s_nand; j++){
        if (st_nor.ent[k] == st_nand.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = snand[y];
            }
          }
        }      
      } for (j = 1; j<=s_or; j++){
        if (st_nor.ent[k] == st_or.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sor[y];
            }
          }
        }      
      } for (j = 1; j<=s_xor; j++){
        if (st_nor.ent[k] == st_xor.saida[j]){
          pos++;
          for(y=0; y<linhas; y++){
            for (g = pos;g<=pos; g++){
              tabela[y][g] = sxor[y];
            }
          }
        }      
      } 
    if (pos == e_nor){
      pos = 0;
    }
  }
  entrada = e_nor;
  cont = 0;
  for (k = 0; k<linhas; k++){    
    g = 1;
    while (g<=entrada){
      if (tabela[k][g] == 0){
        cont++;        
        if (cont == entrada){
          snor[k] = 1;
          cont = 0;
        }
      } else{
        snor[k] = 0;
        cont = 0;
      } 
    g++;
    }
  }
  for (k = 0; k<=s_nor; k++){
    for (j = 1; j<=sai; j++){
      if (st_nor.saida[k] == OUT.OUT[j]){
        for(y=0; y<linhas; y++){          
            saida[y] = snor[y];
        }
      }      
    }
  }
}
void leitura(){
  j = 0;
  for (i = 0; i<=tamanho; i++){     
    if (texto[i] == input[j] || texto[i] == output[j]){  
      p = i;    
      if (texto[i] == 'T' && texto [i-1] == 'U' && texto [i-2] == 'P')
      {        
        if (texto [i-3] == 'N' && texto [i-4] == 'I'){         
          i = 2 + i;         
          ent++;    
          IN.IN[ent] = texto[i];          
        } else if (texto [i-3] == 'T' && texto [i-4] == 'U' && texto [i-5] == 'O'){
            i = 2 + i;
            sai++;
            OUT.OUT[sai] = texto[i];
          }
      } else {
        i = p;
      }
      i = p;
      j++;
    } else {
        j = 0;
    }
  }
}
void leitura2(){
  entradas();
  j = 0;
  for ( i = 0; i<=tamanho; i++){
    if (texto[i] == and_[j] || texto[i] == nor [j] || texto[i] == not_[j] || texto[i] == or_[j] || texto[i] == xor_[j] || texto[i] == nand[j] ){
      p = i;
      e_and = 0, e_nor = 0, e_not = 0, e_nand = 0, e_xor = 0, e_or = 0;
      if ( texto[i] == 'D' && texto[i-1] == 'N' && texto[i-2] == 'A' && texto[i-3] != 'N'){          
        i++;
        while (texto[i]!=10){
          i++;
          a = i + 1;
          if (texto[i]!=' ' && texto[i]!=10 && texto[a]!= 10){            
            e_and++;
            st_and.ent[e_and] = texto[i];  
          } if ( texto[i]!= 10 && texto[a] == 10){
              s_and++;
              st_and.saida[s_and] = texto[i];
              exp_and();
            }
          }  
        } else if (texto[i]=='R' && texto[i-1]=='O' && texto[i-2]=='N'){
          i++;
          while(texto[i]!=10){
            i++;
            a = i+1;
            if (texto[i]!=' ' && texto[i]!=10 && texto[a]!= 10){            
              e_nor++; 
              st_nor.ent[e_nor] = texto[i];                 
            } if ( texto[i]!= 10 && texto[a] == 10){
                s_nor++;
                st_nor.saida[s_nor] = texto[i];
                exp_nor();
          }
        }         
      } else if (texto[i]=='R' && texto[i-1]=='O' && texto[i-2]!='N'){
          i++;
          while(texto[i]!=10){
            i++;
            a = i+1;
            if (texto[i]!=' ' && texto[i]!=10 && texto[a]!= 10){            
              e_or++; 
              st_or.ent[e_or] = texto[i];                 
            } if ( texto[i]!= 10 && texto[a] == 10){
                s_or++;
                st_or.saida[s_or] = texto[i];
                //printf("SAIDA: %c", )
                exp_or();
          }
        }         
      } else if (texto[i]=='D' && texto[i-1]=='N' && texto[i-2]=='A' && texto[i-3]=='N'){
        i++;
        while(texto[i]!=10){
          i++;
          a = i+1;
          if (texto[i]!=' ' && texto[i]!=10 && texto[a]!= 10){ 
            e_nand++;           
            st_nand.ent[e_nand] = texto[i];       
          } if ( texto[i]!= 10 && texto[a] == 10){
            s_nand++;
            st_nand.saida[s_nand] = texto[i];
            exp_nand();
          }
        }         
      } else if (texto[i]=='R' && texto[i-1]=='O' && texto[i-2]=='X'){
        i++;
        while(texto[i]!=10){
          i++;
          a = i+1;
          if (texto[i]!=' ' && texto[i]!=10 && texto[a]!= 10){ 
            e_xor++;           
            st_xor.ent[e_xor] = texto[i];       
          } if ( texto[i]!= 10 && texto[a] == 10){
            s_xor++;
            st_not.saida[s_xor] = texto[i];
            exp_xor();
          }
        }         
      } else if (texto[i]=='T' && texto[i-1]=='O' && texto[i-2]=='N'){
        i++;
        while(texto[i]!=10){
          i++;
          a = i+1;
          if (texto[i]!=' ' && texto[i]!=10 && texto[a]!= 10){ 
            e_not++;           
            st_not.ent[e_not] = texto[i];       
          } if ( texto[i]!= 10 && texto[a] == 10){
            s_not++;
            st_not.saida[s_not] = texto[i];
            exp_not();
          }
        }         
      } else {
          i = p;
        }
        i = p;
        j++;
    } else{
      j = 0;
    }
  }  
}
int main(void) {
  FILE *file;
  char arq[100];
  printf("DIGITE O DIRETORIO/NOME DO ARQUIVO: ");
  scanf ("%s", arq);
  file = fopen(arq, "r");
  char ch;
  if (file == NULL){
    printf("Este arquivo não pode ser aberto");
    exit(0);
  }
  while( (ch=fgetc(file))!= EOF ){
      texto[i]=ch; //Aqui cada caractere é colocado no array
      i++;
  }  
  texto[i]='\0';
  fclose(file);    
  tamanho = strlen(texto)+1;
  printf(" \n \n");
  for (i=0; i<tamanho; i++){
    printf("%c", texto[i]);
  }
  printf("\n \n");
  leitura();
  leitura2();
  printf(" --------------- \n");
  for (i=65; i<65+ent;i++){
  	printf(" %c |", i);
  }
  printf("| S ");
  printf(" \n --------------- \n");
     
  for (i=0;i<linhas; i++){
    for(j = 1; j<=ent;j++){
      printf(" %d |", IN.e[i][j]);         
    }
    printf("| %d ",saida[i]);   
    printf("\n");
  }
  return 0;
}
