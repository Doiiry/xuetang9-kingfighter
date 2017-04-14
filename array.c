//
// Created by xm on 2016/12/19.
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SCORE_SIZE 30

typedef struct Prop{
    char* name;
    double price;
    int stoc;
} Props;

int main(){
    Props* p = malloc(sizeof(Props));
    p->name = "���";
    p->price = 22.0;
    printf("%s,%d",p->name,p->price);
    getch();
    return 0;
}

//int main(){
//    int scores[] = {67,33,92,86,79,100};
//    int len = sizeof(scores)/sizeof(int);
//    int i ,j;
//    /*// ð������
//    for(i=0;i<len-1;i++){
//        for(j=0;j<len-i-1;j++){
//            if(scores[j] < scores[j+1]){
//                int tmp = scores[j];
//                scores[j]=scores[j+1];
//                scores[j+1] = tmp;
//            }
//        }
//    }*/
//    // ��������
//    for( i=1;i<len;i++){
//        for(j=i;j>0;j--){
//            if(scores[j]<scores[j-1]){
//                int temp=scores[j];
//                scores[j]=scores[j-1];
//                scores[j-1]=temp;
//            }else{
//                break;
//            }
//        }
//    }
//
//    // ���
//    for(i=0;i<len;i++){
//        printf("%d\t",scores[i]);
//    }
//    getch();
//    return 0;
//}


int main_(){
    // ������������
    int scorearr[SCORE_SIZE] ; // = {652,706,704}
    char provinces[SCORE_SIZE][50] ;
    // �������е�������0���
    memset(scorearr,0, sizeof(scorearr));
    memset(provinces,0,sizeof(provinces));
    // ��ӷ���, ���ݳ�ʼ��
    scorearr[0] = 652; // ����
    scorearr[1] = 706; // �ӱ�
    scorearr[2] = 704; // ����
    // {"����","�ӱ�","����"}
//    provinces[0] = "����";
//    provinces[1] = "�ӱ�";
//    provinces[2] = "����";
    strcpy(provinces[0],"����");
    strcpy(provinces[1],"�ӱ�");
    strcpy(provinces[2],"����");
    // �˵�
    char  menu[][200]={
            " ���������ѡ��\n",
            "1. �鿴���з���\n",
            "2. ���״Ԫ����\n",
            "3. ָ�����״Ԫ�������\n",
            "4. ��ѯָ��ʡ��״Ԫ����\n",
            "5. �޸�ָ��ʡ��/���״Ԫ����\n",
            "6. ɾ��ָ��ʡ��/���״Ԫ����\n",
            "7. ״Ԫ�񣨸������ܷ֡�ƽ���֣�\n",
            "8. �˳�\n"
    };
    // �Ƿ��˳�����
    int exit_app = 0;
    while(!exit_app){
        system("cls");
        // չʾ�˵���Ϣ
        int i;
        for(i=0;i<9;i++){
            printf("%s",menu[i]);
        }
        // �����û��ļ�������
        int choice = getch();
        system("cls");
        switch(choice){
            case '1': // �鿴���з���
                printf("���\tʡ��\t����\n");
                int r_index;
                for(r_index=0;r_index<SCORE_SIZE;r_index++){
                    if(scorearr[r_index] > 0){
                        printf("%d\t%s\t%d\n",r_index+1,provinces[r_index],scorearr[r_index]);
                    }
                }
                printf("������˳�");
                getch();
                break;
            case '2': // ���״Ԫ�������ڵ�һ��
                while(1){
                    // �ڿյ�һ��λ��
                    for(i = SCORE_SIZE-1;i>1;i--){
                        scorearr[i] = scorearr[i-1];
                        //provinces[i] = provinces[i-1];
                        strcpy(provinces[i],provinces[i-1]);
                    }
                    printf("�������:");
                    scanf("%d",&scorearr[0]); // ���շ���
                    printf("����ʡ������:");
                    scanf("%s",&provinces[0]);
                    printf("�������?(y/n):");
                    if('y'!=getch()){
                        break;
                    }
                }
                break;
            case '3': // ָ��������״Ԫ����
                while(1){
                    printf("�������λ��:");
                    int index;
                    scanf("%d",&index);
                    index--;
                    if(index > SCORE_SIZE -1 || index < 0){
                        printf("��Ų�����. ���������롣���������.");
                        getch();
                        system("cls");
                    }
                    // �ڿյ�һ��λ��
                    for(i = SCORE_SIZE-1;i>=index;i--){
                        scorearr[i] = scorearr[i-1];
                        // provinces[i] = provinces[i-1];
                        strcpy(provinces[i],provinces[i-1]);
                    }
                    printf("�������:");
                    scanf("%d",&scorearr[index]); // ���շ���
                    printf("����ʡ������:");
                    scanf("%s",&provinces[index]);
                    printf("�������?(y/n):");
                    if('y'!=getch()){
                        break;
                    }
                }
                break;
            case '4': // ��ѯָ����š�ʡ��״Ԫ����
                while(1){
                    printf("��������.(ʡ�ݲ�ѯ����0)");
                    int read_index;
                    scanf("%d",&read_index);
                    char province_name[50];
                    if(!read_index){
                        printf("������ʡ������:");
                        scanf("%s",&province_name);
                        for(i=0;i<SCORE_SIZE;i++){
                            if(!strcmp(provinces[i],province_name)){
                                read_index=i;
                                break;
                            }
                        }
                        if(i == SCORE_SIZE){
                            printf("�Ҳ�������ʡ��,���������");
                            getch();
                            system("cls");
                        }
                    }else{
                        read_index--;
                        if(read_index > SCORE_SIZE -1 || read_index < 0){
                            printf("��Ų�����. ���������롣���������.");
                            getch();
                            system("cls");
                        }
                    }
                    printf("���\tʡ��\t����\n");
                    printf("%d\t%s\t%d\n",read_index+1,provinces[read_index],scorearr[read_index]);
                    printf("��������?(y/n):");
                    if('y'!=getch()){
                        break;
                    }
                }
                break;
            case '5': // �޸�ָ����š�ʡ��״Ԫ����
                while(1){
                    printf("��������.(ʡ�ݲ�ѯ����0)");
                    int read_index;
                    scanf("%d",&read_index);
                    char province_name[50];
                    if(!read_index){
                        printf("������ʡ������:");
                        scanf("%s",&province_name);
                        for(i=0;i<SCORE_SIZE;i++){
                            if(!strcmp(provinces[i],province_name)){
                                read_index=i;
                                break;
                            }
                        }
                        if(i == SCORE_SIZE){
                            printf("�Ҳ�������ʡ��,���������");
                            getch();
                            system("cls");
                        }
                    }else{
                        read_index--;
                        if(read_index > SCORE_SIZE -1 || read_index < 0){
                            printf("��Ų�����. ���������롣���������.");
                            getch();
                            system("cls");
                        }
                    }
                    printf("�������:");
                    scanf("%d",&scorearr[read_index]); // ���շ���

                    printf("�޸ĳɹ��������޸�?(y/n):");
                    if('y'!=getch()){
                        break;
                    }
                }
                break;
            case '6': // ɾ��ָ����š�ʡ��״Ԫ����
                while(1){
                    printf("��������.(ʡ�ݲ�ѯ����0)");
                    int del_index;
                    scanf("%d",&del_index);
                    char province_name[50];
                    if(!del_index){
                        printf("������ʡ������:");
                        scanf("%s",&province_name);
                        for(i=0;i<SCORE_SIZE;i++){
                            if(!strcmp(provinces[i],province_name)){
                                del_index=i;
                                break;
                            }
                        }
                        if(i == SCORE_SIZE){
                            printf("�Ҳ�������ʡ��,���������");
                            getch();
                            system("cls");
                        }
                    }else{
                        del_index--;
                        if(del_index > SCORE_SIZE -1 || del_index < 0){
                            printf("��Ų�����. ���������롣���������.");
                            getch();
                            system("cls");
                        }
                    }
                    // �������
                    memset(provinces[del_index],0,sizeof(provinces[del_index]));
                    scorearr[del_index] = 0;
                    printf("����ɾ��?(y/n):");
                    if('y'!=getch()){
                        break;
                    }
                }
                break;
            case '7': // ״Ԫ�񣨸������ܷ֡�ƽ���֣�
                printf("\n");
                int arr_len = 0; // ������
                double sum_score = 0; // �ܷ�
                double avg_score = 0; // ƽ����
                for(i=0;i<SCORE_SIZE;i++){
                    if(scorearr[i]>0){
                        arr_len++;
                        sum_score+=scorearr[i];
                    }
                }
                avg_score = sum_score/arr_len;
                printf("������\t�ܷ�\tƽ����\n");
                printf("%d\t\t%.0lf\t%.2lf\n",arr_len,sum_score,avg_score);
                printf("���������:");
                getch();
                break;
            case '8':
                exit_app=1;
                break;
            default:
                printf("ѡ����Ч�����������\n");
                getch();
                break;
        }
    }
    return 0;
}
