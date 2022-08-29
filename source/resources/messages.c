#include <stdio.h>

const char *status_messages[600];
const char *error_messages[600];
const char *credit_messages[600];

int loadStatusMessages()
{
    status_messages[0] = "...";
    status_messages[1] = "Neue Partie wird Initialisiert...";
    status_messages[2] = "Neue Partie wird gestartet!";
    status_messages[3] = "Anzahl der Versuche:";
    status_messages[4] = "Anzahl der Buchstaben des gesuchten Worts: ";
    status_messages[5] = "Der geratene Buchstabe ist:";
    status_messages[6] = "richtig";
    status_messages[7] = "falsch";
    status_messages[8] = "\nDrücke [Enter] um fortzufahren...";
    status_messages[9] = "Wort: ";
    status_messages[10] = "Versuch Nummer: ";
    status_messages[11] = "Fehlversuche übrig: ";
    status_messages[12] = "Eingabe: ";
    status_messages[13] = "Versuchte Buchstaben: ";
    status_messages[14] = "Buchstaben eingeben und anschließend\nmit [Enter] bestätigen → ";
    status_messages[15] = "Überprüfung...";
    status_messages[16] = "Buchstabe kommt im gesuchten Wort vor!";
    status_messages[17] = "Buchstabe kommt im gesuchten nicht Wort vor!";
    status_messages[18] = "Spiel verloren :(";
    status_messages[19] = "Spiel gewonnen :)";
    return 1;
}

int loadErrorMessages()
{
    error_messages[0] = "Buchstabe wurde berreits verwendet";
    error_messages[1] = "Eingabe unzulässig!\nNur einzelne Buchstaben zulässig.\n(Keine Zahlen, Groß/Kleinschreibung spielt keine Rolle)";
    error_messages[2] = "Error";
    error_messages[3] = "Bitte nur einen Buchstaben eingeben.";
    error_messages[4] = "Bitte erneut versuchen.";
    return 1;
}
int loadCreditMessages()
{
    credit_messages[0] = "© Maximilian Müller";
    credit_messages[1] = "https://github.com/mxmueller";
    return 1;
}

int loadMessages()
{
    if (loadCreditMessages() && loadErrorMessages() && loadStatusMessages())
        return 1;
    return 0;
}
