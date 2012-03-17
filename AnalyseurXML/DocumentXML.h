#ifndef H_DOCUMENT_XML
#define H_DOCUMENT_XML

#include <string>

#include "NodeList.h"
#include "../AnalyseurDTD/DTDValidator.h"

class DocumentXML
{
 public:
  std::string dtd, document, xsl;
  NodeList XMLRootNode;
  NodeList XSLRootNode;
  NodeList XHTMLRootNode;
  DTDValidator XMLValidator;
  DTDValidator XSLValidator;

  DocumentXML(sdt::string document);
  void parseXML();
  void parseDTD();
  void parseXSL();
  bool validate();

  bool parse();
  void render();
};

#endif
