// XML.h: interface for the CXML class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XML_H__81944A00_9DA5_11D4_B8A3_0050BAB0DED8__INCLUDED_)
#define AFX_XML_H__81944A00_9DA5_11D4_B8A3_0050BAB0DED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Msxml.h>
#import "MSXML.DLL" named_guids

/*
	Generalized class for parsing an XML file
	Author:Deepu.L.R,
	Org:M2
*/

enum AddPos {LEFT,APPEND};

#define USETREECTRL

class CXML  
{
protected:
	HRESULT m_hr;
	
	IXMLDOMNode			*m_pIRootNode;
	IXMLDOMDocument		*m_pXMLDoc;
	IXMLDOMNode			*m_pICurrentNode;
	IXMLDOMElement		*m_pIRootElement;
	IXMLDOMParseError	*m_pParseError;
	IXMLDOMNodeList		*m_pNodeList;
	IXMLDOMNode			*m_pINewElement;
	int nRelease;

	CString m_csXmlFileName;
#ifdef USETREECTRL
	CTreeCtrl	* m_pTreeCtrl;
#endif	

	bool GetNode(IXMLDOMNode ** pNode,CString &rcsPathToNode,LPCTSTR lpszAttribute,LPCTSTR lpszValue,bool bUseBase = false);	
	
	bool GetRootNode(CString lpszRootTagName);
	bool AddNode(IXMLDOMNode **ppRefNode,IXMLDOMNode **ppINodeToAdd,IXMLDOMNode **ppINewNode,DOMNodeType nodeType,AddPos ePos = APPEND);
	bool CreateAttributeNode(IXMLDOMNode **pParentNode,CString csAttribute,CString csValue);
	bool RemoveAttributeNode(IXMLDOMNode **pParentNode,CString csAttribute);
	bool CreateCommentNode(IXMLDOMNode **ppParentNode,CString &rcsComment);
	bool CreateNodeText(IXMLDOMNode **pNode,CString &rcsNodeText);
	bool Delete(IXMLDOMNode **ppRemoveNode);
	bool GetNodeAttributeValue(IXMLDOMNode ** ppNode,CString csAttributeName,CString &rcsValue);
	bool ReplaceNodeText(IXMLDOMNode **pNode,CString &rcsNodeText);

#ifdef USETREECTRL
	void Looop(IXMLDOMNode * pCurrentNode,HTREEITEM hParent,HTREEITEM hInsertAfter);
	IXMLDOMNode *NextChildNode(IXMLDOMNode **ppNode);
	IXMLDOMNode *NextSib(IXMLDOMNode **ppNode);
	bool GetNodeName(IXMLDOMNode **ppNode,CString & rcsNodeName);
#endif

public:
	bool GoToRootNode();
	bool GetCurrentNodeName(CString & rcsNodeNmae);
	bool NextSibling();
	bool PreviousSibling();
	bool MoveToParentNode(UINT nNthParent = 1);
	bool HasChildNode();
	bool HasAttributes();
	bool NextChildNode();
	bool GetAttributeValue(CString csAttributeName,CString &rcsValue);
	bool GetAttributeValue(CString csPathToNode,CString csAttributeName,CString &rcsValue,bool bCurrentNodeAsBase = false);
	bool GetNodeText(CString csPathToNode,CString csAttribute,CString csAttValue,CString &rcsValue,bool bCurrentNodeAsBase = false);
	bool GetNodeText(CString csPathToNode,CString &rcsValue,bool bCurrentNodeAsBase = false);
	bool GetNodeText(CString &rcsValue);
	bool GetNodeXML(CString &rcsValue);
	bool GetNodeXML(CString csPathToNode,CString csAttribute,CString csAttValue,CString &rcsValue,bool bCurrentNodeAsBase = false);
	bool GetNodePath(CString &csPath);
	bool GetNoOfChildNodes(long &nNodes);
	IXMLDOMNode * GetCurrentNode();
	IXMLDOMNode * CloneNode();
	bool SetCurrentNode(IXMLDOMNode * pXMLDOMNode);
	bool SetNode(IXMLDOMNode *pDomNode);
	bool GoToNode(CString csPathToNode,bool bCurrentNodeAsBase = false);
	bool GoToNode(CString csPathToNode,CString csAttribute,CString csValue,bool bCurrentNodeAsBase = false);
	bool GoToNodeEx(CString csPathToNode,CString csNodeText,bool bCurrentNodeAsBase = false);
	bool GoToNodeEx(CString csPathToNode,char **ppTagNames,char** ppAttributes,char **ppValues,int nTagCount,bool bCurrentNodeAsBase = false);
	CXML();
	virtual ~CXML();
	void Close();
	bool Initialize();
	bool LoadFile(LPCTSTR lpszXmlFile);
	bool LoadString(LPCTSTR lpszXmlString);
	bool LoadXMLFromDOM( IXMLDOMNode** pXMLDOMNode);

///////////////////Functions for manipulating a list of nodes having same name////////////
	bool GetNodesList(CString csPathToNode,bool bCurrentNodeAsBase = false);	
	bool GetItemsCount(long * pnCount);
	bool ResetList();
	bool NextNodeInList();
	bool NodeInList(long nIndex);

////////////////// Functions for adding and deleting tags///////////////////
	
	bool CreateElement(CString csTagName,LPCTSTR lpszText,char ** ppAttributes,char ** ppValues,int nNoOfAttributes,bool bSetAsCurNode = false);
	bool CreateAttribute(CString csAttribute,CString csValue);
	bool CreateAttribute(CString  csPathToNode,CString csAttribute,CString csValue,bool bCurrentNodeAsBase = false);
	bool CreateComment(CString csComment);
	bool Save(LPCTSTR lpszFileName = NULL);
	bool DeleteNode(CString csPathToNode,bool bCurrentNodeAsBase = false);
	bool DeleteNode(CString csPathToNode,CString csAttribute,CString csValue,bool bCurrentNodeAsBase = false);
	bool DeleteNode();
	bool AddNodeText(CString &csNodeText);
	bool AddNodeText(CString csPathToNode,CString csNodeText,bool bCurrentNodeAsBase);
	bool ReplaceNodeText(CString csNodeText);
	bool ReplaceNodeText(CString csPathToNode,CString csNodeText,bool bCurrentNodeAsBase);
	bool SetAttributeValue(CString csAttributeName,CString csValue);
	bool SetAttributeValue(CString csPathToNode,CString csAttributeName,CString csValue,bool bCurrentNodeAsBase = false);

#ifdef USETREECTRL
	bool Populate(CTreeCtrl &treeCtrl);
#endif
};

#endif // !defined(AFX_XML_H__81944A00_9DA5_11D4_B8A3_0050BAB0DED8__INCLUDED_)
