#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <pthread.h>
#include <conio.h>
/**
 * �������Ѫ��
 */
#define BASE_HP 2000
/**
 * ���ܸ���
 */
#define SKILL_SIZE 11
/**
 * �����û�������߳�
 * @param th
 * @return
 */
void* demoth(void* th){
    char* in = (char*)th;
    while(1){
        char v = *in;
        if(!v){
            fflush(stdin);
            *in = getch();
        }else if(v==-1){
            break;
        }
        usleep(50*1000);
    }
    return (void*)0;
}
/***
 * ��ں���
 * @return
 */
int main() {
    // ����
    // ��ɫ����
    char names [][50] = {"������","���꾩","K","���ޡ�������ɭ/��ɭ������ѷ","̩��������","�����","K9999","ʸ������","����","����ǧ��"};
    //  ��������
    char skill_names [][50] = {"�ռ伯����ɱ","������Դ","��ʥ֮��������","��ʥ֮�������","�����","����","�ۺ���","��֮Ѫ","������","�����ȭ","��ʯ��"};
    // ������С����ֵ
    int skill_min_power[]={100,120,90,130,110,170,100,88,99,60,130};
    // ������󹥻�ֵ
    int skill_max_power[]={260,220,140,150,140,250,200,190,260,180,260};
    // ������ϼ�
    char skill_keys[][20] = {"include","stdio.h","int","main","printf","return","short","long","float","double","char"};
    // ��ӭ��������
    char wellcomData[][1000] = {"���մ�������֮�������˼䡣",
                               "����һ��Ư����Ů���ں��п������������׸�������ߵļ�Ʒ������֮�о��������Ů�ӣ��浾�Ｇ����ת�� ���ɾ���Ů��Сѩ������֮�а������浾�Ｇ����ɱ���˰�����ߣ�������β��ȡ�����������ɽ���",
                               "����֮�и��浾�Ｇ�మ�� ��������֮�еĺ��� ��Ϊ�����ɡ������˳����������롱������壬���ǹ�ͬ�ػ���������������(����),����(��),����(����)����ӡ�������",
                               "��������Ȱ˳�����°�����һ��������Ů�����Ǹ�Ů��Ҳ���ϰ˳�����£����ǲ��ɾ������Ȳ�������Ҳ�����˹��������ǳ������������Ƕ��˴�һ�� ��˭Ӯ�˾Ϳ���������Ů�����˳������������������ֵ� �����������֣������������̫����λС���ˡ��Ѱ˳�����´�����ˣ����������ò������յ��Լ���Ů�����˳�����¶Բ�������˵�ӽ��������ǲ������ֵܡ�",
                               "Ϊ�˱���˳�����¾�������һ����ߵ�������������������ձ����˳�����������ŭ�Ѱ˳�����¹����������ڼ����а˳��������ʱ���̶��������Ź�����������ߵĲл��ջ�˳�����������⿪��ӡ�������Ը�����������ѹ��������������ð˳�����¿����˹�������������Ű���ľ��󣬰˳��������Ҳ�޷������ˣ��⿪�˴��ߵķ�ӡ���Ӵ˸���Ϊ����",
                               "������³�ȥ������˲��ص�����һϢ�Ĺ�������������˵�����£��Ұ���ֻ���㣬Ȼ���ҵ��ˡ�����������ʱ����˵��������һֱ���ڰ��㣬�㲻�ý⿪��ӡ�ģ�������һ���ٰѴ��߷�ӡ�ɣ��������ͬ���˲�������˵�� ���ٴν������������������Ѵ��߷�ӡ����������������������Թ�Ӵ˽����ˡ�",
                               "���������ֵĸ��װ����°����˲��ɾ��ĸ��ײ��ɲ��۵����¹ҵ��ˡ������ָ����ɾ�����˵���޵�Ҳ����˵�Ǳ˴����˽�Է����ˡ�",
                               "�ٺ���ȭ�ʴ������񱻴����������еı�������Ȼ����˴���֮Ѫ�������ˣ����ǲ��ɾ�һȭ������� �������������ɾ��������֣�����ǧ������������һ��ѽ��ÿ���˹����Ϊ��ý����Ĵ����ٴη�ӡ������֮�����˵Ĳ��ɾ���N.E.S.T.S��֯���˴��� ���ò��ɾ����׵����� �����˺ܶ�ð�ƵĲ��ɾ���������ȥN.E.S.T.S��֯���˺ö��",
                               "Ȼ�������Ѿ�����ͣ���ڲ��ɾ��Ͱ����֣�����Խ��Խ������˼��롣���ò��ɾ� ���������K ���Է���������ASH�����ɾ���Ů����Сѩ�������Ů���Ǹ��ֹȼ���������ҵ��ˡ�����Ϊ�������׸衶Ϧ�����¡�",
                               };

    // �浵
    // �浵����
    char record_names[10][50];
    // ѡ���ɫ����
    char record_select_role_names[10][50];
    // ��ս��ɫ����
    char record_attack_role_names[10][50];
    // ��Ϸ����
    int record_score [10];
    // ��Ϸ���
    short record_result[10];
    // �浵ʱ��
    char record_times[10][50];
    // �浵����
    int record_size = 0;

    // �˵�
    // ���˵�
    char menu_home[][100] = {"\n\n\n\t\t\t+-----------------------------------------------------------------------+",
                            "\t\t\t|\t\t\t��ӭ����C���԰�ȭ�ʡ���ѡ��\t\t\t|",
                            "\t\t\t|\t\t\t1.\t��ʼ����Ϸ\t\t\t\t|",
                            "\t\t\t|\t\t\t2.\t��������\t\t\t\t|",
                            "\t\t\t|\t\t\t3.\t�˳�\t\t\t\t\t|",
                            "\t\t\t|\t\t\t \t\t\t\t\t\t|",
                            "\t\t\t+-----------------------------------------------------------------------+"
                            };
    // ��Ϸ�˵�
    char menu_pay[][100] = {"\n\n\n\t\t\t+-----------------------------------------------------------------------+",
                             "\t\t\t|\t\t\t\t��ɫѡ��\t\t\t\t|",
                            "\t\t\t|\t\t\t1.\t������\t\t\t\t\t|",
                            "\t\t\t|\t\t\t2.\t���꾩\t\t\t\t\t|",
                            "\t\t\t|\t\t\t3.\tK\t\t\t\t\t|",
                            "\t\t\t|\t\t\t4.\t���ޡ�������ɭ/��ɭ������ѷ\t\t|",
                            "\t\t\t|\t\t\t5.\t̩��������\t\t\t\t|",
                            "\t\t\t|\t\t\t6.\t�����\t\t\t\t\t|",
                            "\t\t\t|\t\t\t7.\tK9999\t\t\t\t\t|",
                            "\t\t\t|\t\t\t8.\tʸ������\t\t\t\t|",
                            "\t\t\t|\t\t\t9.\t����\t\t\t\t\t|",
                            "\t\t\t|\t\t\ta.\t����ǧ��\t\t\t\t|",
                            "\t\t\t|\t\t\tb.\t����  \t\t\t\t\t|",
                            "\t\t\t|\t\t\t \t\t\t\t\t\t|",
                            "\t\t\t+-----------------------------------------------------------------------+"
                            };
    // �浵�˵�
    char menu_record[][100] = {"\n\n\n\t\t\t+-----------------------------------------------------------------------+",
                               "\t\t\t|\t\t\t\t�浵����\t\t\t\t|",
                               "\t\t\t|\t\t\t1.\t�鿴\t\t\t\t\t|",
                               "\t\t\t|\t\t\t2.\tɾ��\t\t\t\t\t|",
                               "\t\t\t|\t\t\t3.\t����\t\t\t\t\t|",
                               "\t\t\t|\t\t\t4.\t����\t\t\t\t\t|",
                               "\t\t\t|\t\t\t5.\t�˳�\t\t\t\t\t|",
                               "\t\t\t|\t\t\t\t\t\t\t\t\t|",
                               "\t\t\t+-----------------------------------------------------------------------+"
                                };

    // ���������
    srand(time(0));

    // ��Ϸ������չʾ����
    int i ,j ;
    for(i = 0;i<9;i++){
        char info [1000];
        strcpy(info,wellcomData[i]);
        int size = strlen(info);
        printf("\t");
        for(j=0;j<size;j++){
            printf("%c",info[j]);
            Sleep(1);
        }
        printf("\n\n");
        Sleep(500);
    }
    // �û�ѡ����
    char choice;
    // �˳�������
    short exit_game;
    // �����������
    while(1){
        exit_game = 0;
        system("cls");
        // չʾ���˵�
        for(i=0;i<7;i++){
            printf("%s\n",menu_home[i]);
        }
        // �����û�ѡ��
        choice = getch();
        switch(choice){
            case '1':
                    while(1){
                        // ���ѡ��Ľ�ɫ����
                        char pay_role_name[50];
                        // ���Ҫ��ս�Ľ�ɫ����
                        char pay_attack_name[50];
                        short to_main = 0;
                        // �û�ѡ�������
                        int round;
                        for(round=0;round<2;round++){
                            system("cls");
                            // չʾ��Ϸ�˵�
                            for(i=0;i<16;i++){
                                printf("%s\n",menu_pay[i]);
                            }
                            //  �����û�ѡ��
                            choice = getch();
                            int cindex;
                            if(choice >= 49 && choice <= 57 ){
                                cindex = choice - 49;
                            }else if('a'==choice){
                                cindex = choice - 88;
                            }else if('b'==choice){
                                to_main = 1;
                                break;
                            }else{
                                printf("û�����ѡ��,��Ч������Ϊ(1 - 9 ���� a ��b)...");
                            }
                            if(round == 0){
                                strcpy(pay_role_name,names[cindex]);
                                // ��ʾ�û���ѡ��
                                printf("��ѡ��Ľ�ɫ��:%s.�����ѡ����Ҫ��ս�Ľ�ɫ�������������",pay_role_name);

                            }else{
                                strcpy(pay_attack_name,names[cindex]);
                                printf("��Ҫ��ս�Ľ�ɫ��:%s.������������鿴����˵����\n\n\n",pay_attack_name);
                            }
                            getch();
                        }
                        // �ص�������
                        if(to_main){
                            break;
                        }
                        system("cls");
                        printf("\n��ͨ����:ÿ�β���60-80�㹥���������ܵĹ���������Ŷ��\n");
                        printf("����\t\t ������ϼ�\n\n");
                        // ��ʾ��Ϣ
                        for(i=0;i<SKILL_SIZE;i++){
                            printf("%s\t\t%s\n",skill_names[i],skill_keys[i]);
                        }
                        printf("\n\n�������ʼ��Ϸ!");
                        getch();
                        // ��ҵķ���
                        int score_pay = 0;
                        // ��ʼ��Ϸ
                        int role_hp,user_hp;
                        // ����
                        system("cls");
                        // �̱߳���
                        pthread_t  th;
                        // ������ձ���
                        char input = 0;
                        // ��ʼ���û��ͽ�ɫ��Ѫ��
                        user_hp = role_hp = BASE_HP;
                        // ������������߳�
                        int thCode = pthread_create(&th,NULL,demoth,(void*)&input);
                        // ��ҵ���ϼ�
                        char player_input_keys [20];
                        // �������ĳ���
                        int player_input_size = 0;
                        // ��ҵĹ�����
                        int player_skill_power;
                        //  NPC�Ĺ�����
                        int npc_skill_power;
                        // �����ļ����ֻ���
                        int attack_count;
                        while(user_hp  && role_hp){
                            attack_count++;
                            // ������ҵ�����, ���Ҽ��㹥����
                            if(input){
                                int attact_succes = 0;
                                if(input != 'k'){
                                    // �û���������ĳ���
                                    int input_key_len = strlen(player_input_keys);
                                    if(input_key_len >= sizeof(player_input_keys)/sizeof(char)-1){
                                        // ����һ��ȫ���������Ʋ���
                                        int input_arr_len;
                                        for(input_arr_len = 0;input_arr_len < sizeof(player_input_keys)/sizeof(char)-1;input_arr_len++){
                                            player_input_keys[input_arr_len] = player_input_keys[input_arr_len+1];
                                        }
                                        player_input_keys[input_arr_len]=0;
                                        player_input_size-=1;
                                    }
                                    player_input_keys[player_input_size++] = input;
                                    player_input_keys[player_input_size] = 0;
                                    int key_index;
                                    for(key_index=0;key_index<SKILL_SIZE;key_index++){
                                        // ��ȡ��ǰ�ؼ��ֳ���
                                        int skill_key_len = strlen(skill_keys[key_index]);
                                        // �����ȡ��������,Ȼ��Ƚ�
                                        char nowKeyGet[20];

                                        // �û�����û�дﵽ��׼�����ȡ�ִ����һ�ֱ�׼���Ƚ�
                                        if(input_key_len < skill_key_len){
                                            continue;
                                        }
                                        // �����ȡ�û�������
                                        int now_read_index;
                                        for(now_read_index=0;now_read_index < skill_key_len; now_read_index++){
                                            nowKeyGet[now_read_index] = player_input_keys[input_key_len-(skill_key_len - now_read_index )];
                                        }
                                        nowKeyGet[now_read_index] = 0;
                                        if(!strcmp(nowKeyGet,skill_keys[key_index])){
                                            break;
                                        }
                                    }
                                    if(key_index < SKILL_SIZE){
                                        attact_succes = 1;
                                        // ������Ҳ����Ĺ�����
                                        player_skill_power = rand()%(skill_max_power[key_index]-skill_min_power[key_index])+skill_min_power[key_index];
                                        printf("�㷢���˴���:%s\n",skill_names[key_index]);
                                        printf("������%d�Ĺ�����.\n",player_skill_power);
                                        // ����÷�
                                        score_pay+= player_skill_power * 0.03;
                                    }
                                }else{
                                    attact_succes = 1;
                                    player_skill_power = rand()%20 + 60;
                                    printf("�㷢������ͨ����.\n");
                                    printf("������%d�Ĺ�����.\n",player_skill_power);
                                    // ����÷�
                                    score_pay+= player_skill_power * 0.03;
                                }
                                if(attact_succes){
                                    // NPC Ѫ������
                                    role_hp -= player_skill_power;
                                    role_hp = role_hp < 0 ? 0:role_hp;
                                    printf("%s��ǰ��Ѫ��Ϊ:%d\n",pay_attack_name,role_hp);
                                    printf("------------------------------------------\n\n");
                                    attact_succes = 0;
                                }
                                input = 0;
                            }

                            // ����NPC�Ĺ�����
                            if(!(attack_count % 10)){
                                int npc_skill_index = rand()%SKILL_SIZE;
                                if(rand()%4==3){
                                    npc_skill_power = rand()%20 + 60;
                                    printf("%s��������ͨ����.\n",pay_attack_name);
                                }else{
                                    npc_skill_power = rand()%(skill_max_power[npc_skill_index]-skill_min_power[npc_skill_index])+skill_min_power[npc_skill_index];
                                    printf("%s�����˴���:%s\n",pay_attack_name,skill_names[npc_skill_index]);
                                }
                                printf("������%d�Ĺ�����.\n",npc_skill_power);
                                // Ѫ������
                                user_hp -= npc_skill_power;
                                user_hp = user_hp < 0 ? 0:user_hp;
                                printf("�㵱ǰ��Ѫ��Ϊ:%d\n\n",user_hp);
                            }
                            Sleep(100);
                        }
                        // �߳��˳���ʶλ
                        input = -1;
                        // ��Ϸ�������ж��߳�
                        pthread_cancel(th);
                        printf("��Ϸ����!");
                        if(!user_hp){
                            printf("%s�ɵ����ˡ�������Ϸʧ��!\n",pay_attack_name);
                            score_pay+=5;
                        }else if(!role_hp){
                            printf("��ɵ���%s.��ϲ�㡣\n\n",pay_attack_name);
                            score_pay+=30;
                        }
                        // ��¼�浵
                        if(record_size==10){
                            printf("�浵���������Ḳ�����´浵...");
                            record_size--;
                        }
                        // ����
                        char rec_name[50];
                        long long t = time(0); // �Ժ���ֵ��¼��ǰʱ��
                        sprintf(rec_name,"rec_%lld",t);
                        strcpy(record_names[record_size],rec_name);
                        // ѡ���ɫ��
                        strcpy(record_select_role_names[record_size],pay_role_name);
                        // ������ɫ��
                        strcpy(record_attack_role_names[record_size],pay_attack_name);
                        //  ����
                        record_score[record_size] = score_pay;
                        //  ���
                        record_result[record_size] = user_hp > 0 ;
                        //  ��¼ʱ��
                        time_t  now;
                        struct tm* info;
                        time(&now);
                        info = localtime(&now);
                        sprintf(record_times[record_size],"%d-%d-%d %d:%d:%d",info->tm_year+1900,info->tm_mon,info->tm_mday,info->tm_hour,info->tm_min,info->tm_sec);
                        // ��¼����
                        record_size++;
                        fflush(stdin);
                        sleep(2);
                        // �ж��Ƿ������Ϸ�ı���
                        char continueGame = 0;
                        printf("������Ϸ?(y/n)");
                        scanf("%c",&continueGame);
                        if(continueGame!='y'){
                            break;
                        }
                    }
                break;
            case '2':
                while(1){
                    // �浵����
                    system("cls");
                    // չʾ�浵�˵�
                    for(i=0;i<9;i++){
                        printf("%s\n",menu_record[i]);
                    }
                    // �����û�ѡ��
                    choice = getch();
                    int exit_record = 0;
                    switch(choice){
                        case '1': // �鿴
                            system("cls");
                            if(record_size){
                                printf("���\t����\t\tѡ���ɫ\t\t������ɫ\t\t����\t���\tʱ��\n\n");
                                for(i=record_size-1;i>=0;i--){
                                    printf("%d\t%s\t%s\t\t%s\t\t%d\t%s\t%s\n",(record_size-i),record_names[i],record_select_role_names[i],record_attack_role_names[i],
                                           record_score[i],record_result[i]?"ʤ��":"ʧ��",record_times[i]);
                                }
                            }else{
                                printf("��û�������Ϸ��¼�ء�Ҫ��ȥ��һ��..\n");
                            }
                            printf("���������");
                            getch();
                            break;
                        case '2': // ɾ��
                            while(1){
                                system("cls");
                                printf("������Ҫɾ���ļ�¼���:");
                                int del_record;
                                scanf("%d",&del_record);
                                if(--del_record < record_size && del_record >= 0){
                                    for(i=del_record;i<record_size-1;i++){
                                        strcpy(record_names[i],record_names[i+1]);
                                        strcpy(record_select_role_names[i],record_select_role_names[i+1]);
                                        strcpy(record_attack_role_names[i],record_attack_role_names[i+1]);
                                        record_score[i] = record_score[i+1];
                                        record_result[i] = record_result[i+1];
                                        strcpy(record_times[i],record_times[i+1]);
                                    }
                                    printf("�Ѿ�ɾ�ˡ�����ɾ(y/n)?");
                                }else{
                                    printf("���û���ԡ�������(y)/��ȥ��һ��(n)");
                                }
                                if('y'!=getch()){
                                    break;
                                }
                            }
                            break;
                        case '3': // ����
                            while(1){
                                system("cls");
                                printf("������Ҫ�޸ĵļ�¼���:");
                                int update_record;
                                scanf("%d",&update_record);
                                if(--update_record < record_size && update_record >= 0){
                                    printf("д������Ҫ������:");
                                    scanf("%s",&record_names[update_record]);
                                    printf("�Ѿ��ĺ��ˡ����Ÿ�(y/n)?");
                                }else{
                                    printf("���û���ԡ�������(y)/��ȥ��һ��(n)");
                                }
                                if('y'!=getch()){
                                    break;
                                }
                            }
                            break;
                        case '4': // ����
                            system("cls");
                            // �����������
                            int record_sort_index[10],j;
                            // ��ʼ���������
                            for(i=0;i<record_size;i++){
                                record_sort_index[i]=i;
                            }
                            // ���շ����Ӹߵ��������ƶ��������
                            for(i=0;i<record_size-1;i++){
                                for(j=0;j<record_size-i-1;j++){
                                    if(record_score[i] < record_score[i+1]){
                                        int tmp = record_sort_index[i];
                                        record_sort_index[i] = record_sort_index[i+1];
                                        record_sort_index[i+1] = tmp;
                                    }
                                }
                            }
                            // �������
                            printf("���\t����\tѡ���ɫ\t\t������ɫ\t\t����\t���\tʱ��\n\n");
                            // ������Ž������
                            for(i=0;i<record_size;i++){
                                int index = record_sort_index[i];
                                printf("%d\t%s\t%s\t\t%s\t\t%d\t%s\t%s\n",(i+1),record_names[index],record_select_role_names[index],
                                       record_attack_role_names[index],record_score[index],record_result[index]?"ʤ��":"ʧ��",
                                       record_times[index]);
                            }
                            printf("�������������!");
                            getch();
                            break;
                        case '5': // �˳�
                            exit_record = 1;
                            break;
                        default:
                            printf("\n����������ȷѡ��(��ѡ��Ϊ1-5)\n");
                            break;
                    }
                    if(exit_record){
                        break;
                    }
                }
                break;
            case '3':
                exit_game = 1;
                break;
            default:
                printf("\n\n\n��Ҫ�������˵���ѡ��ֻ��1��2��3Ŷ��\n");
                break;
        }
        if(exit_game){
            printf("��Ϸ����..\n");
            Sleep(2000);
            break;
        }
    }
    return 0;
}