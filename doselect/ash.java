int main (void)
{
    char input[1000]= {'\0'}; //the sentence the user will enter
    printf("Enter a sentence:");
    scanf("%[^\n]", input);
    char newSentence[1000]={'\0'};
    sentence=(char *) &newSentence;
    line=getText(input,0);
    divide(input);
    printf("%s\n",sentence);
    return 0;
}
