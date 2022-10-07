// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageParser.h"

FString UMessageParser::parseMessages(FString allMessages) {
	FString showMessages = FString();
	int nlcount = 0;
	int i = allMessages.Len() - 1;;
	while (i >= 0 && nlcount <= 5) {
		if (allMessages[i] == '\n') {
			nlcount++;
		}
		if (nlcount <= 5) {
			showMessages = pushFront(showMessages, allMessages[i]);
		}
		i--;
	}
	return showMessages;
}

FString UMessageParser::appendString(FString oldString, FString newString) {
	return oldString + newString;
}

FString UMessageParser::pushFront(FString oldMessage, char c) {
	FString newMessage = FString();
	newMessage += c;
	newMessage += oldMessage;
	return newMessage;
}