entrada = fopen(argv[1],"r");
    saida = fopen(argv[2], "w");
    //entrada = fopen("entrada3.txt","r");
    //saida = fopen("saida3.txt", "w+");
    if (argc != 3){
        printf("ERRO!!!\nNumero de parametros incorreto\n");
        printf("Os parametros devem ser:\n[nome do programa] [arquivo de entrada] [arquivo de saida]\n");
        return 1;
    }
    else if(entrada == NULL){
        printf("ERRO com arquivo de entrada\n");
        return 1;
    }else if(saida == NULL){
        printf("ERRO com arquivo de saida\n");
        return 1;
    }
