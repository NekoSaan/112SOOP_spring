/************************************************************************
File:
		Email.h
Author:
		Kuo Po Wei, powei30445@gmail.com
Create Date:
		2024/04/30
Editor:
		Kuo Po Wei, powei30445@gmail.com
Edit Date:
		2024/04/30
Description:
		Declare Email class
************************************************************************/
#ifndef _EMAIL_H_
#define _EMAIL_H_
#include "Document.h"

// Email class, inherti Document
class Email : public Document {
private:
	string sender;
	string recipient;
	string title;
	
public:
	// Default Constructor
	Email(string text, string sender, string reci, string title) :
		Document::Document(text), sender(sender), recipient(reci), title(title) {};

	// Get sender
	string getSender(void);

	// Get recipent
	string getRecipient(void);

	// Get title
	string getTitle(void);
};

#endif // _EMAIL_H_