////////////////////////////////////////////////////////////////////////////////
// Copyright 2003 Siemens Product Lifecycle Management Software Inc.
// All Rights Reserved.
//
// This software and related documentation are proprietary to
// Siemens Product Lifecycle Management Software Inc.
////////////////////////////////////////////////////////////////////////////////

#ifndef JTK_PARSER_HXX
#define JTK_PARSER_HXX

#include<JtTk/JtkEntity.h>

class JtkParserContext;
class JtkParserAction;
class JtkParser;


///////%{
//
// Class          : JtkParser
//
// Description    : Toolkit class for performing ASCII parsing.  The grammar
//                  is described by a hierarchy of JtkParserContext and
//                  JtkParserAction objects, and parsing is performed by the
//                  callbacks associated with these objects.
//
// Enums          : ParserControl:
//                     JtkCONTINUE -- Callback response indicating "OK".
//                     JtkFINISH -- Callback response indicating that the
//                        current parse() invocation is to be terminated.
//                     JtkERROR -- Callback response indicating that an error
//                        occurred.
//
// Includes       : JtkParser.h
//
// Inheritance    : JtkRefCounted > JtkParser
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkParser : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkParser )

public:
   enum ParserControl {JtkCONTINUE, JtkFINISH, JtkERROR};
   typedef ParserControl JtkParserCB(JtkParser* ThisParser);

   //parsing related methods
   virtual int parse(const JtkString& InputFileName)=0;
   virtual int fileOk(void)=0;
   virtual int foundEOF(void)=0;
   virtual int foundDelimiter(char inputChar)=0;
   virtual int setDelimiters(const JtkString& seperatorList)=0;
   virtual int getDelimiters(JtkString&  seperatorList)=0;
   virtual int addUnusedItem(const JtkString& item)=0;
   virtual int clearUnusedItems()=0;
   virtual int getParseState(JtkEntity* &TopState) = 0;

   //access the root context
   virtual JtkParserContext* getRootContext()=0;

   // root context manipulations
   virtual int numContexts()=0;
   virtual JtkParserContext *context(int Index)=0;
   virtual int addContext(JtkParserContext *ContextToAdd)=0;
   virtual int deleteContext(JtkParserContext *ContextToDelete)=0;
   virtual int deleteContext(int Index)=0;

   // root action manipulations
   virtual int numActions()=0;
   virtual JtkParserAction *action(int Index)=0;
   virtual int addAction(JtkParserAction *ActionToAdd)=0;
   virtual int deleteAction(JtkParserAction *ActionToDelete)=0;
   virtual int deleteAction(int Index)=0;

   // user accessible "skip ahead" methods,
   // skips one item unless option number is specified
   virtual int skipNext(int, int NumItems=1)=0;
   virtual int skipNext(long, int NumItems=1)=0;
   virtual int skipNext(float, int NumItems=1)=0;
   virtual int skipNext(double, int NumItems=1)=0;
   virtual int skipNext(char, int NumItems=1)=0;
   virtual int skipNext(JtkString& , int FullLine=0, int NumItems=1)=0;

   // user accessible "get data" parsing methods
   virtual int getNext(int &IntegerToGet)=0;
   virtual int getNext(long &LongToGet)=0;
   virtual int getNext(float &FloatToGet)=0;
   virtual int getNext(double &DoubleToGet)=0;
   virtual int getNext(char &CharToGet)=0;
   virtual int getNext(JtkString& StringToGet, int FullLine=0)=0;

   // user accessible "get data last seen" parsing methods
   //this will work only in conjunction with the ::addUnusedItem(JtkString& item=0)
   virtual int getLast(int &IntegerToGet)=0;
   virtual int getLast(long &LongToGet)=0;
   virtual int getLast(float &FloatToGet)=0;
   virtual int getLast(double &DoubleToGet)=0;
   virtual int getLast(char &CharToGet)=0;
   virtual int getLast(JtkString& StringToGet)=0;

protected:
   //constructor and destructor
   JtkParser();
   virtual ~JtkParser();
};


///////%{
//
// Class          : JtkParserContext
//
// Description    : The class of object used by a JtkParser object to
//                  define the context for detecting and performing a
//                  grammar's actions (i.e., objects of type JtkParserAction).
//                  A JtkParser automatically has one context -- the root
//                  context -- with which further actions or contexts are
//                  associated.  A JtkParser grammar consists of a hierarchy
//                  of JtkParserContext and JtkParserAction objects.
//
// Enums          :
//
// Includes       : JtkParserContext.h
//
// Inheritance    : JtkRefCounted > JtkParserContext
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkParserContext : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkParserContext )

public:
   // RegExpr APIs
   virtual int setBeginRegExpr( const JtkString& TheRegExpr )=0;
   virtual int getBeginRegExpr( JtkString& TheRegExprBuffer )=0;
   virtual int setEndRegExpr( const JtkString& TheRegExpr )=0;
   virtual int getEndRegExpr( JtkString& TheRegExprBuffer )=0;

   // Context manipulations
   virtual int numContexts()=0;
   virtual JtkParserContext *context(int Index)=0;
   virtual int addContext(JtkParserContext *ContextToAdd)=0;
   virtual int deleteContext(JtkParserContext *ContextToDelete)=0;
   virtual int deleteContext(int Index)=0;

   //context begin and end checks
   virtual JtkParserContext *matchContextBegin(const JtkString& StringToCheck)=0;
   virtual int matchContextEnd(const JtkString& StringToCheck)=0;  // Note, if returns 'this', then found context end expr...

   //check for defined contextCB
   virtual int isContextBeginCB()=0;
   virtual int isContextEndCB()=0;

   // Action manipulations
   virtual int numActions()=0;
   virtual JtkParserAction *action(int Index)=0;
   virtual int addAction(JtkParserAction *ActionToAdd)=0;
   virtual int deleteAction(JtkParserAction *ActionToDelete)=0;
   virtual int deleteAction(int Index)=0;
   virtual JtkParserAction *matchAction(const JtkString& StringToCheck)=0;

protected:
   //constructor and destructor
   JtkParserContext();
   virtual ~JtkParserContext();
};


///////%{
//
// Class          : JtkParserAction
//
// Description    : The class of object used by a JtkParser object to
//                  identify a grammar token and perform a user action.
//                  Actions are used to define the most atomic units of
//                  parsing work in a grammar.
//
// Enums          :
//
// Includes       : JtkParserAction.h
//
// Inheritance    : JtkRefCounted > JtkParserAction
//
// Visibility     : public
//
// Theory         :
//
///////%}
class JTK_TOOLKIT_API JtkParserAction : public JtkRefCounted
{
   JTK_OBJECT_HEADER( JtkParserAction )

public:
   //check for defined actionCB
   virtual int isActionCB()=0;

   // RegExpr APIs
   virtual int setRegExpr( const JtkString& TheRegExpr )=0;
   virtual int getRegExpr( JtkString& TheRegExprBuffer )=0;

   // Test for action regexpr match
   virtual int matchAction(const JtkString& StringToCheck)=0;

protected:
   //constructor and destructor
   JtkParserAction();
   virtual ~JtkParserAction();
};

#endif

