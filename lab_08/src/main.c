#include "print.h"
#include "graph_func.h"
#include "exceptions.h"

int main(void)
{
    setbuf(stdout, NULL);
    print_info();

    int key = 1, error_code = 0;
    int flag_graph = 1;
    // int error_code = 0;
    graph_struct_t graph;
    // char filename[20] = "";


    while (key)
    {
        print_menu();
        if (scanf("%d", &key) != 1 || key < 0 || key > 4)
        {
            printf("Введён неверный пункт меню.\n");
            return ERROR_KEY;
        }
        switch(key)
        {
            case(0):
            {
                printf("Программа успешно завершена по вашему желанию.\n");
                return EXIT_SUCCESS;
            }
            case(1):
            {
                error_code = create_matrix(&graph);
                if (error_code)
                    return error_code;
                
                flag_graph = 0;

                printf("\nМатрица смежностей успешно считана.\n\n");
                break;
            }
            case(2):
            {
                if (flag_graph)
                {
                    printf("\nДля вывода матрицы смежности необходимо считать её в пункте 1.\n\n");
                    break;
                }
                print_matrix(graph);
                break;
            }
            case(3):
            {
                if (flag_graph)
                {
                    printf("\nДля вывода графа необходимо считать его в пункте 1.\n\n");
                    break;
                }

                show_graph(&graph);

                system("dot -Tpng graph.gv > graph.png");
                system("xdg-open graph.png");
                break;
            }
            case(4):
            {
                if (flag_graph)
                {
                    printf("\nДля работы с графом необходимо считать его в пункте 1.\n\n");
                    break;
                }
                is_connected_graph(&graph);

                break;
            }
            default:
            {
                printf("\nВведён неверный пункт меню.\n\n");
                return error_code;
            }
        }
    }
    
   	return error_code;
}