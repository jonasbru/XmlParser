#include <cstring>

#include "DocumentXML.h"

using namespace std;


int parseXMLFile(char* file, DocumentXML * doc);


DocumentXML::DocumentXML(char* document, char* xsl)
{
  dtd = NULL;
  
  this->document = (char*)malloc(strlen(document)+1);
  strcpy(this->document, document);

  if (xsl != NULL){
    this->xsl = (char*)malloc(strlen(xsl)+1);
    strcpy(this->xsl, xsl);
  }
}

//this should set dtd and xsl
void DocumentXML::parseXML()
{
  //document is set
  if (document == NULL)
    return;

  this->state = "XML";
  parseXMLFile(document, this);
}

void DocumentXML::parseDTD()
{
  if (dtd == NULL)
    return;


}

void DocumentXML::parseXSL()
{
  if (xsl == NULL)
    return;

  this->state = "XSL";
  parseXMLFile(xsl, this);
}


void recursiveTreeSearch(NodeList root)
{	
	
	//Looking for a template!
	map<string, string>::iterator templateLook;
	for (templateLook = (XSLRootNode.childNodeList).begin() ; templateLook != (XSLRootNode.childNodeList).end(); templateLook++)
	{
		if(templateLook->nameSpace == "xsl"
		&& templateLook->tagName == "template"
		&& templateLook->attributes["match"] == root.tagName())
		{
			cout << root.tagName() << endl;
			break;
		}
	}
	
	
	list<Node*>::iterator it;
	for (it = (root.childNodeList).begin() ; it != (root.childNodeList).end(); it++)
	{
		recursiveTreeSearch(*it);
	}
}

void DocumentXML::processXSLT()
{
  if (XMLRootNode == NULL
	|| XSLRootNode == NULL)
    return;

	// Useless
  this->state = "ProcessXSLT";
  
  string currentXMLTag = XMLRootNode.tagName;
  string currentXSLNode = XSLRootNode;
  
  recursiveTreeSearch(XMLRootNode);
  
}

bool DocumentXML::validate()
{
  //TODO 
  return false;
}

bool DocumentXML::parse()
{
  parseXML();
  parseDTD();
  parseXSL();

  return validate();
}

void DocumentXML::render()
{
  
}
