#include <stdio.h>

const char * status_messages[600];
const char * error_messages[600];
const char * credit_messages[600];

int load_status_messages()
{
    status_messages[0] = "...\n";
    status_messages[1] = "Neue Partie wird Initialisiert.\n";
    status_messages[2] = "Neue Partie wird gestartet!\n";
    status_messages[3] = "Anzahl der Versuche:\n";
    status_messages[4] = "Anzahl der Buchstaben des gesuchten Worts: ";
    status_messages[5] = "Der geratene Buchstabe ist:\n";
    status_messages[6] = "richtig\n";
    status_messages[7] = "falsch\n";
    status_messages[8] = "\nDrücke 'Enter' um Spiel zu starten...\n";
    status_messages[9] = "Wort: ";
    status_messages[10] = "Versuch Nummer: ";
    status_messages[11] = "Fehlversuche übrig: ";
    status_messages[12] = "Eingabe: ";
    return 1;
}

int load_error_messages()
{
    error_messages[0] = "Buchstabe wurde berreits verwendet\n";
    error_messages[1] = "Nur Buchstaben zulässig!\n";
    error_messages[2] = "Error\n";
    return 1;
}
int load_credit_messages() 
{
    credit_messages[0] = "© Maximilian Müller\n";
    credit_messages[1] = "https://github.com/mxmueller\n";
    return 1;
}

