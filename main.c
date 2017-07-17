//
// Created by Erik on 26.06.2017.
//
#include "helper.h"
#include "time.h"
#include "string.h"

struct s_key * createKey(char * inp, size_t len) {
  if ((strlen(inp) == 5) && (len == 5) ) {
      if ((inp[0] >= 'A' && inp[0] <= 'Z') && (inp[1] >= 'A' && inp[1] <= 'Z')
          && (inp[2] >= '0' && inp[2] <= '9') && (inp[3] >= '0' && inp[3] <= '9')
          && (inp[4] >= '0' && inp[4] <= '9')) {

          struct s_key *nkey = malloc(sizeof(struct s_key));
          nkey->nr3 = (enum Enumber) (inp[4] - '0');
          nkey->nr2 = (enum Enumber) (inp[3] - '0');
          nkey->nr1 = (enum Enumber) (inp[2] - '0');
          nkey->y = (enum Eletter) (inp[1] - 'A');
          nkey->x = (enum Eletter) (inp[0] - 'A');

          return nkey;
      }
  }
  return NULL;
}

struct s_element * createElement(struct s_key * k) {
    struct s_element * nelement = malloc(sizeof(struct s_element));
    if (!k) return NULL;

    nelement->removed = 0;
    nelement->data = 0;
    nelement->key.nr1 = k->nr1;
    nelement->key.nr2 = k->nr2;
    nelement->key.nr3 = k->nr3;
    nelement->key.x = k->x;
    nelement->key.y = k->y;

    free(k);
    return nelement;
}


int main(int argc, char** argv)
{
    int running = 0;
    int action = -1;
    char signal_wait[20];
    char key_input[20];

    
    //Init the _Map
    srand((unsigned int)time(NULL));
    initialize();
    probe_function = simple_probe;
    hash_function = simple_hash;

    //Generating & inserting 1000 Random Entries
    struct s_element * k, * l;
    int probe = 0, maxprobesteps = 0;

    for (int i = 0; i < 1000 ; i++) {
        k = genKey();
        int res = insert(k);
        if (res == TABLE_KEY_EXISTS) {
            free(k);
            i--;
            continue;
        }
        if (res == TABLE_FULL) {
            printf("Tabelle voll!\n");
            break;
        }
        
        probe = lastProbingSteps;
        if (maxprobesteps < lastProbingSteps) 
        {
            maxprobesteps = lastProbingSteps;
        }

        l = get(k->key);
        l->data = probe;
    }
    
    //Main Loop
    while (running == 0)
    {
        for(int c = 0; c < 20; ++c) key_input[c] = '\0';
        system("clear");
        printf("Bitte Waehlen:\n--------------\n1) Map anzeigen\n2)Element einfuegen\n3)Element loeschen\n4)Element suchen\n0)Programm beenden\n--------------\n");
        scanf("%d", &action);
        struct s_key * nkey;
        switch (action) {
            case 1:
                print_array(hash_table, TABLE_LENGTH);
                break;
            case 2:
                scanf("%s", key_input);
                struct s_element * nelement = createElement(createKey(key_input, strlen(key_input)));
                if (nelement != NULL) {
                    struct s_element *last;

                        int res = insert(nelement);
                        if (res == TABLE_KEY_EXISTS) {
                            printf("Schluessel existiert bereits\n");
                            free(nelement);
                            break;
                        }
                        if (res == TABLE_FULL) {
                            printf("Map voll!\n");
                            break;
                        }
                        probe = lastProbingSteps;
                        if (maxprobesteps < lastProbingSteps) {
                            maxprobesteps = lastProbingSteps;
                        }
                        last = get(nelement->key);
                        if (nelement != last && !last) {
                            printf("Fehler beim einfügen. Abbruch\n");
                            break;
                        }
                        last->data = probe;
                        printf("Eingefügter Schluessel: %s Sondierungen: %d\n", key_input, last->data);
                    } else {
                        printf("Schluessel muss in der Form XYnnn eingegeben werden\n");
                        break;
                    }
                break;
            case 3:
                scanf("%s", key_input);
                nkey = createKey(key_input, strlen(key_input));
                if (nkey != NULL) {
                    int ret = rem(*nkey);
                    if (ret != 0) {
                        printf("Etwas lief schief beim loeschen: ");
                        if (ret == TABLE_KEY_NOT_FOUND) printf("Schluessel nicht in Tabelle vorhanden\n");
                        break;
                    } else {
                        printf("Element %s erfolgreich geloescht\n", key_input);
                    }
                    free(nkey);
                } else {
                    printf("Schluessel muss in der Form XYnnn eingegeben werden\n");
                    break;
                }
                break;
            case 4:
                scanf("%s", key_input);
                nkey = createKey(key_input, strlen(key_input));
                if (nkey != NULL) {
                    struct s_element *elem = get(*nkey);
                    if (elem == NULL) {
                        printf("Etwas lief schief beim suchen: Schluessel nicht in Tabelle vorhanden\n");
                        break;
                    } else {
                        printf("Element %s wurde mit folgenden Daten (= Sondierung) gespeichert: %d\n", key_input,
                               elem->data);
                    }
                    free(nkey);
                } else {
                    printf("Schluessel muss in der Form XYnnn eingegeben werden\n");
                    break;
                }
            break;
        case 0:
            running = 1;
            printf("Programm wird beendet.\n");
            break;
        default:
            printf("Ungueltige Eingabe.\n");
            break;
        }
        printf("ENTER druecken, um fortzufahren\n");
        scanf("%s",signal_wait);
        
    }
    
    //Clear Map
    for (int i = 0; i < TABLE_LENGTH; i++) {
        free(hash_table[i]);
    }
    
    // End Program
    if(running == 1)
    {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
