// XML.cpp: implementation of the CXML class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XML.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CXML::CXML()
{
	m_pIRootNode	= NULL;
	m_pXMLDoc		= NULL;
	m_pICurrentNode = NULL;
	m_pIRootElement = NULL;
	m_pParseError	= NULL;
	m_pINewElement	= NULL;
	m_pNodeList		= NULL;
	
}


void CXML::Close()
{
	int i = 0;
	if(m_pIRootNode)
	{
		i = m_pIRootNode->Release();
		m_pIRootNode = 0;
	}

	if(m_pICurrentNode)
	{
		i = m_pICurrentNode->Release();
		m_pICurrentNode = 0;
	}

	if(m_pIRootElement)
	{
		i = m_pIRootElement->Release();
		m_pIRootElement = 0;
	}

	if(m_pINewElement)
	{
		i = m_pINewElement->Release();
		m_pINewElement = 0;
	}
	
	if(m_pNodeList)
	{
		i = m_pNodeList->Release();
		m_pNodeList = 0;
	}
}


bool CXML::Initialize()
{
	if(!m_pXMLDoc)
	{
		m_hr = CoCreateInstance(CLSID_DOMDocument, NULL, CLSCTX_INPROC_SERVER, 
								IID_IXMLDOMDocument, (void**)&m_pXMLDoc); // check the return value, hr...
		if(!SUCCEEDED(m_hr))
			return false;

		VARIANT_BOOL vIsAsync=FALSE;

		m_hr = m_pXMLDoc->put_async(vIsAsync);
		if(!SUCCEEDED(m_hr))
			return false;

	}

	return true;
}

/*
	 Function name		: CXML::LoadFile
	 Description	    : This function load the given XML file using
						  m_pXMLDoc object. 	
	 Return type		: bool 
	 Argument			: LPCTSTR lpszXmlFile
	 Tested				: Ok
 */	
bool CXML::LoadFile(LPCTSTR lpszXmlFile)
{
	if (!lpszXmlFile || !m_pXMLDoc)
		return false;

	m_csXmlFileName = lpszXmlFile;
	long lXmlSate = 0;
	
	_variant_t vtFileName(m_csXmlFileName);
   
	VARIANT_BOOL vSuccess;
	m_hr = m_pXMLDoc->load(vtFileName,&vSuccess);

	if(!SUCCEEDED(m_hr) || vSuccess == FALSE)
	{
		return FALSE;
	}

	m_hr = m_pXMLDoc->get_readyState(&lXmlSate);
    if(SUCCEEDED(m_hr) && lXmlSate == 4)
	{	

		m_hr = m_pXMLDoc->get_documentElement(&m_pIRootElement);
		if(SUCCEEDED(m_hr) == 0)
			return false;

		BSTR bstrTagName;
		m_pIRootElement->get_tagName(&bstrTagName);
		CString csRootTag = bstrTagName;


		SysFreeString(bstrTagName);

		if(GetRootNode(csRootTag))
		{
			m_pICurrentNode = m_pIRootNode;
			m_pICurrentNode->AddRef();
		}
		else
			return false;
	}
	else
		return false;

	return true;
}

/*
	 Function name		: CXML::LoadString
	 Description	    : This function load the given XML String using
						  m_pXMLDoc object. 	
	 Return type		: bool 
	 Argument			: LPCTSTR lpszXmlFile
	 Tested				: Ok
 */	
bool CXML::LoadString(LPCTSTR lpszXmlString)
{
	if (!lpszXmlString || !m_pXMLDoc)
		return false;
	
	_bstr_t bstrXMLString(lpszXmlString);
	long lXmlSate = 0;
   
	VARIANT_BOOL vSuccess;
	m_hr = m_pXMLDoc->loadXML(bstrXMLString,&vSuccess);


	if(!SUCCEEDED(m_hr) || vSuccess == FALSE)
	{
		return FALSE;
	}

	m_hr = m_pXMLDoc->get_readyState(&lXmlSate);
    if(SUCCEEDED(m_hr) && lXmlSate == 4)
	{	
		m_hr = m_pXMLDoc->get_documentElement(&m_pIRootElement);
		if(!SUCCEEDED(m_hr))
			return false;

		BSTR bstrTagName;
		m_pIRootElement->get_tagName(&bstrTagName);
		CString csRootTag;

		csRootTag = bstrTagName;
		SysFreeString(bstrTagName);

		if(GetRootNode(csRootTag))
		{
			m_pICurrentNode = m_pIRootNode;
			m_pICurrentNode->AddRef();
		}
		else
				return false;
	}
	else
		return false;

	return true;
}

/*
	 Function name		: CXML::LoadXMLFromDOM
	 Description	    : This function set the curretn an root node as the DOMNode passed as arg						  
	 Return type		: bool 
	 Argument			: IXMLDOMNode** ppXMLDOMNode
	 Tested				: Ok
 */	
bool CXML::LoadXMLFromDOM( IXMLDOMNode** ppXMLDOMNode)
{
	if(*ppXMLDOMNode == NULL || !m_pXMLDoc)
		return false;

	if(m_pIRootNode)
	{
		m_pIRootNode->Release();
		m_pIRootNode = NULL;
	}
	m_pIRootNode = *ppXMLDOMNode;
	m_pIRootNode->AddRef();

	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = NULL;
	}

	m_pICurrentNode = *ppXMLDOMNode;
	m_pICurrentNode->AddRef();

	return true;
}

/*
	 Function name		: CXML::~CXML
	 Description	    : Destuctor releses all interface pointers
	 Tested				: Ok
 */	
CXML::~CXML()
{
	Close();
	if(m_pXMLDoc)
	{
		int i = m_pXMLDoc->Release();
		m_pXMLDoc = 0;
	}
}

/*
	Function name	: CXML::GetRootNode
	Description	    : This helper function retrieves the DOM pointer to the root node
	Return type		: bool 
	Argument        : CString csRootTagName
	Tested			: Ok
*/
bool CXML::GetRootNode(CString csRootTagName)
{
	IXMLDOMNodeList * pINodeList = NULL;

	_bstr_t bstrRootTagName(csRootTagName);

	m_hr = m_pXMLDoc->getElementsByTagName(bstrRootTagName ,&pINodeList);

	if(!SUCCEEDED(m_hr))
		return false;

	m_hr = pINodeList->nextNode(&m_pIRootNode);
	pINodeList->Release();
	if(!SUCCEEDED(m_hr))
		return false;

	return true;
}


/*
	Function name	: CXML::SetAttributeValue
	Description	    : Sets the current nodes attribute name with the new value. if the current 
					: doesn't have such an attribute name the function fails.
	Return type		: bool 
	Argument        : CString csAttributeName
	Argument        : CString csValue
	Tested			: Ok
*/
bool CXML::SetAttributeValue(CString csAttributeName,CString csValue)
{

	if(RemoveAttributeNode(&m_pICurrentNode,csAttributeName))
		if(CreateAttributeNode(&m_pICurrentNode,csAttributeName,csValue))
			return true;

	return false;
}

/*
	Function name	: CXML::SetAttributeValue
	Description	    : Sets the given nodes attribute name with the new value. if the node
					: doesn't have such an attribute name the function fails.
	Return type		: bool 
	Argument        : CString csPathToNode
	Argument        : CString csAttributeName
	Argument        : CString csValue
	Argument        : bool bCurrentNodeAsBase
	Tested			: Ok
*/

bool CXML::SetAttributeValue(CString csPathToNode,CString csAttributeName,CString csValue,bool bCurrentNodeAsBase)
{
	IXMLDOMNode * pNode = NULL;
	if(!GetNode(&pNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
		return false;

	if(RemoveAttributeNode(&pNode,csAttributeName))
		if(CreateAttributeNode(&pNode,csAttributeName,csValue))
		{
			pNode->Release();
			m_pIRootNode->Release();
			return true;
		}

	pNode->Release();
	
	return false;
}


/*
	 Function name		: CXML::GetAttributeValue
	 Description	    : This function retrives the value of given attribute of the 
						: CurrentNode (m_pICurrentNode)
	 Return type		: bool 
	 Argument			: CString csAttributeName
	 Argument			: CString &rcsValue
	 Tested				: Ok
 */	

bool CXML::GetAttributeValue(CString csAttributeName,CString &rcsValue)
{
	if(!m_pICurrentNode) return false;

	return GetNodeAttributeValue(&m_pICurrentNode,csAttributeName,rcsValue);
}

/*
	Function name	: CXML::GetAttributeValue
	Description	    : This function retrieves the value of the given attribute of the given node
	Return type		: bool 
	Argument        : CString csPathToNode
	Argument        : CString csAttributeName
	Argument        : CString &rcsValue
	Argument        : bool bCurrentNodeAsBase
*/

bool CXML::GetAttributeValue(CString csPathToNode,CString csAttributeName,CString &rcsValue,bool bCurrentNodeAsBase )
{
	IXMLDOMNode *pNode = NULL;

	if(!GetNode(&pNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase ))
		return false;

	bool bRet = GetNodeAttributeValue(&pNode,csAttributeName,rcsValue);
	if(pNode)
		pNode->Release();
	return bRet;
}

/*
	Function name	: CXML::GetNodeAttributeValue
	Description	    : Helper function which retrieves the attribute of the given Node
	Return type		: bool 
	Argument        : IXMLDOMNode ** ppNode
	Argument        : CString csAttributeName
	Argument        : CString &rcsValue
*/

bool CXML::GetNodeAttributeValue(IXMLDOMNode ** ppNode,CString csAttributeName,CString &rcsValue)
{

	IXMLDOMNode *pNodeAttribute = NULL;
	IXMLDOMNamedNodeMap *pNodeMap = NULL;
	CString csTemp;

	if(!ppNode || !(*ppNode))
		return false;

	m_hr =	(*ppNode)->get_attributes(&pNodeMap);

	if (SUCCEEDED(m_hr) == 0 || pNodeMap == NULL) 
		return false;

	_bstr_t bstrAttributeName(csAttributeName);

	m_hr =	pNodeMap->getNamedItem (bstrAttributeName,&pNodeAttribute);	
	pNodeMap->Release();
	if (SUCCEEDED(m_hr) == 0 || (pNodeAttribute == NULL))	
		return false;
	
	_variant_t vtAttributeVal;
	m_hr =	pNodeAttribute->get_nodeValue(&vtAttributeVal);

	pNodeAttribute->Release();

	if (SUCCEEDED(m_hr) == 0)
		return false;
        
	rcsValue = vtAttributeVal.bstrVal;
	return true;	
}
/*
	 Function name		: CXML::GoToRootNode
	 Description	    : This function sets the current Node to the root node.
	 Return type		: bool
	 Tested				: Ok
 */	
bool CXML::GoToRootNode()
{
	if(!m_pIRootNode)
		return false;

	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = NULL;
	}

	m_pICurrentNode = m_pIRootNode;
	m_pICurrentNode->AddRef();
	return true;
}


/*
	 Function name		: CXML::GetNode
	 Description	    : This is a helper function which, gives the pointer to node.
						: searching for node can be started either from the current node
						: or it may be started from the Root Node depending on the value of 
						: bCurrentNodeAsBase.
	 Return type		: bool 
	 Argument			: CString csPathToNode
	 Argument			: LPCTSTR lpszAttribute
	 Argument			: LPCTSTR lpszValue
	 Argument			: bool bCurrentNodeAsBase
	 Tested				: Ok
*/	
bool CXML::GetNode(IXMLDOMNode ** pNode,CString &rcsPathToNode,LPCTSTR lpszAttribute,LPCTSTR lpszValue,bool bCurrentNodeAsBase )
{
	IXMLDOMNode * pBaseNode  = NULL;
	CString csPath("");

	if(bCurrentNodeAsBase)
	{
		if(!m_pICurrentNode) 
			return false;

		pBaseNode  = m_pICurrentNode;
		if(lpszAttribute)
			csPath.Format("./%s[@%s = \"%s\"]",rcsPathToNode,lpszAttribute,lpszValue);
		else
			csPath.Format("./%s",rcsPathToNode);
	}
	else
	{
		if(!m_pIRootNode) 
			return false;

		pBaseNode   = m_pIRootNode;
		if(lpszAttribute)
			csPath.Format("/%s[@%s = \"%s\"]",rcsPathToNode,lpszAttribute,lpszValue);
		else
			csPath.Format("/%s",rcsPathToNode);
	} 
	
	pBaseNode->AddRef();		 

	BSTR bsPathToNode = csPath.AllocSysString();

	m_hr =	pBaseNode->selectSingleNode(bsPathToNode,pNode);

	SysFreeString(bsPathToNode);
	pBaseNode ->Release();
		
	if (!SUCCEEDED(m_hr) || !(*pNode))
		return false;

return true;
}


/*
	Function name	: CXML::CreateNodeText
	Description	    : This helper function Creates a text node as a child node of the pNode.
	Return type		: bool 
	Argument        : IXMLDOMNode **pNode
	Argument        : CString &rcsNodeText
	Tested			: Ok
*/
bool CXML::CreateNodeText(IXMLDOMNode **pNode,CString &rcsNodeText)
{
	IXMLDOMText  * pTextNode = NULL;

	if(!(*pNode))
		return false;

	_bstr_t bstrData(rcsNodeText);

	m_hr = m_pXMLDoc->createTextNode(bstrData,&pTextNode);
	if(!SUCCEEDED(m_hr) || !pTextNode)
		return false;
	
	IXMLDOMNode * pINewNode = NULL;
	m_hr = (*pNode)->appendChild(pTextNode,&pINewNode);
	pTextNode->Release();
	if(!SUCCEEDED(m_hr) || !pINewNode)
		return false;

	pINewNode->Release();
	return true;
}


/*
	Function name	: CXML::AddNodeText
	Description	    : This function adds the given text to the existing text of the current 
					: node.
	Return type		: bool 
	Argument        : CString &rcsNodeText
	Tested			: Ok
*/
bool CXML::AddNodeText(CString &rcsNodeText)
{
	IXMLDOMText  * pTextNode = NULL;

	return CreateNodeText(&m_pICurrentNode,rcsNodeText);
}

/*
	Function name	: CXML::AddNodeText
	Description	    : This function adds the given text to the existing text of the given
					: node. 
	Return type		: bool 
	Argument        : CString csPathToNode
	Argument        : CString csNodeText
	Argument        : bool bCurrentNodeAsBase
	Tested			: Ok
*/

bool CXML::AddNodeText(CString csPathToNode,CString csNodeText,bool bCurrentNodeAsBase )
{
	if(csPathToNode.IsEmpty() || csNodeText.IsEmpty())
		return false;

	IXMLDOMNode *pNode = NULL;
	if(!GetNode(&pNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
		return false;
	bool bRet = CreateNodeText(&pNode,csNodeText);
	if(pNode)
		pNode->Release();
	return bRet;

}
/*
	 Function name		: CXML::ReplaceNodeText
	 Description	    : This function will replace the text of the Current Node
	 Return type		: bool 
	 Argument			: CString &rcsValue	 
	 Tested				: Ok
*/	
bool CXML::ReplaceNodeText(CString csNodeText)
{
	if(csNodeText.IsEmpty())
		return false;

	return ReplaceNodeText(&m_pICurrentNode,csNodeText);
}

/*
	Function name	: CXML::ReplaceNodeText
	Description	    : This function replaces the existing text with the given text of the given 
					: node.
	Return type		: bool 
	Argument        : CString csPathToNode
	Argument        : CString csNodeText
	Argument        : bool bCurrentNodeAsBase
	Tested			: Ok
*/
bool CXML::ReplaceNodeText(CString csPathToNode,CString csNodeText,bool bCurrentNodeAsBase)
{
	if(csNodeText.IsEmpty() || csNodeText.IsEmpty())
		return false;

	IXMLDOMNode * pNode = NULL;
	if(!GetNode(&pNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
		return false;

	bool bRet = ReplaceNodeText(&pNode,csNodeText);
	if(pNode)
		pNode->Release();

	return bRet;
}

/*
	Function name	: CXML::ReplaceNodeText
	Description	    : This Helper function replaces the existing text with the given text of 
					: the given node. 
	Return type		: bool 
	Argument        : IXMLDOMNode **pNode
	Argument        : CString &rcsNodeText
	Tested			: 
*/
bool CXML::ReplaceNodeText(IXMLDOMNode **pNode,CString &rcsNodeText)
{
	IXMLDOMText  * pTextNode = NULL;
	if(!(*pNode))
		return false;

	IXMLDOMNode * pTempNode = NULL;
	DOMNodeType nodeType;
	IXMLDOMNode * pINewNode = NULL;
	IXMLDOMNode * pIOldNode = NULL;
	IXMLDOMNodeList * pChildList = NULL;
	long nLen = 0,i=0;


	_bstr_t bstrData(rcsNodeText);

	m_hr = m_pXMLDoc->createTextNode(bstrData,&pTextNode);
	if(!SUCCEEDED(m_hr) || !pTextNode)
		goto on_Error;	


	m_hr = (*pNode)->get_childNodes(&pChildList);
	if(!SUCCEEDED(m_hr) || !pChildList)
		goto on_Error;
	
	m_hr = pChildList->get_length(&nLen);
	if(!SUCCEEDED(m_hr))
		goto on_Error;

	if(nLen == 0)	// no childs, if the tag is empty
	{
		bool bRet = CreateNodeText(pNode,rcsNodeText);
		if(pChildList)
			pChildList->Release();
		if(pTextNode)
			pTextNode->Release();
		return bRet;		
	}

	for(i =0; i< nLen;++i)
	{
		m_hr = pChildList->nextNode(&pTempNode);
		if(!SUCCEEDED(m_hr))
			goto on_Error;

		m_hr = pTempNode->get_nodeType(&nodeType);
		if(!SUCCEEDED(m_hr))
			goto on_Error;

		if(nodeType == NODE_TEXT)
			break;

		if(pTempNode)
		{
			pTempNode->Release();
			pTempNode = NULL;
		}
	}

	m_hr = (*pNode)->replaceChild(pTextNode,pTempNode,&pINewNode);
	if(!SUCCEEDED(m_hr) || !pINewNode)
			goto on_Error;

	if(pChildList)
		pChildList->Release();
	if(pTextNode)
		pTextNode->Release();
	if(pINewNode)
		pINewNode->Release();
	if(pTempNode)
		pTempNode->Release();

	return true;


on_Error:	// Release all the References

	if(pChildList)
		pChildList->Release();
	if(pTextNode)
		pTextNode->Release();
	if(pINewNode)
		pINewNode->Release();
	if(pTempNode)
		pTempNode->Release();
	
	return false; 
}



/*
	 Function name		: CXML::GetAttributeValue
	 Description	    : This function will return the XML between the current node.
	 Return type		: bool 
	 Argument			: CString &rcsValue	
	 Tested				: Ok
*/	
bool CXML::GetNodeXML(CString &rcsValue)
{
	BSTR bsNodeText;
	if(!m_pICurrentNode)
		return false;

	m_hr = m_pICurrentNode->get_xml(&bsNodeText);
	if (!SUCCEEDED(m_hr) || !bsNodeText)
		return false;

	rcsValue = bsNodeText;
	SysFreeString(bsNodeText);
	return true;
}

/*
	 Function name		: CXML::GetNodePath
	 Description	    : This function will return the full path of the xml file. (Max up to 
						: 100 Nodes)
	 Return type		: bool 
	 Argument			: CString &rcsPath
	 Tested				: Ok
 */	
bool CXML::GetNodePath(CString &rcsPath)
{
	if(!m_pICurrentNode)
		return false;

	char * path[100] = {0};
	
	IXMLDOMNode * pCurNode = m_pICurrentNode;
	IXMLDOMNode * pParentNode = NULL;
	pCurNode->AddRef();
	CString csNodeText;

	int i = 0;
	try
	{
		do
		{
			m_hr = pCurNode->get_parentNode(&pParentNode);
			if(!SUCCEEDED(m_hr))
			{
				pCurNode->Release();
				throw 1;
			}
			else if(!pParentNode)
				break;

			BSTR bstrNodeText;
			m_hr =	pParentNode->get_nodeName(&bstrNodeText);
			pCurNode->Release();
			pCurNode = pParentNode;
			pCurNode->AddRef();
			pParentNode->Release();

			if(!SUCCEEDED(m_hr))
			{
				throw 1;
			}
			
			long nLen = wcslen(bstrNodeText)+1;
			path[i] = new char[nLen];
 			WideCharToMultiByte(CP_ACP,0,bstrNodeText,-1,path[i],nLen,NULL,NULL);		
			SysFreeString(bstrNodeText);
			i++;
		}
		while(true);
		
		delete [] path[--i];
		for(--i;i>=0;--i)
		{
			rcsPath += path[i];
			rcsPath +="/";
			delete [] path[i];
		}

		GetCurrentNodeName(csNodeText);
		rcsPath +=csNodeText;
		return true;
	}
	catch(...)
	{
		rcsPath = "";
		for(--i;i>=0;--i)		
			delete [] path[i];
		return false;
	}	
}

/*
	 Function name		: CXML::GetNodeText
	 Description	    : This function will return the text between the current node.
	 Return type		: bool 
	 Argument			: CString &rcsValue	 
	 Tested				: Ok
 */	
bool CXML::GetNodeText(CString &rcsValue)
{
	BSTR bstrNodeText;
	if(!m_pICurrentNode)
		return false;

	m_hr = m_pICurrentNode->get_text(&bstrNodeText);
	if (!SUCCEEDED(m_hr) || !bstrNodeText)
		return false;

	rcsValue = bstrNodeText;
	SysFreeString(bstrNodeText);
	return true;
}


/*
	 Function name		: CXML::GetNodeText
	 Description	    : This function will give node text.
						: searching for the node starts either from the current node
						: or it may start from the Root Node depending on the value of 
						: bool bCurrentNodeAsBase .
	 Return type		: bool 
	 Argument			: CString csPathToNode
	 Argument			: CString &rcsValue
	 Tested				: Ok
 */	
bool CXML::GetNodeText(CString csPathToNode,CString &rcsValue,bool bCurrentNodeAsBase )
{	

	IXMLDOMNode *pINodeData = NULL;
	
	if(!GetNode(&pINodeData,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
		return false;

	BSTR bstrNodeText;

	m_hr = pINodeData->get_text(&bstrNodeText);
	pINodeData->Release();
	if (!SUCCEEDED(m_hr) || !bstrNodeText)
		return false;

	rcsValue = bstrNodeText;
	
	SysFreeString(bstrNodeText);
	return true;
}

/*
	 Function name		: CXML::GetNodeText
	 Description	    : This function will give node text.
						: searching for the node starts either from the current node
						: or it may start from the Root Node depending on the value of 
						: bool bUseBase.
	 Return type		: bool 
	 Argument			: CString csPathToNode
 	 Argument			: CString csAttribute
	 Argument			: CString csAttValue
	 Argument			: CString &csValue
	 Argument			: bool bCurrentNodeAsBase
	 Tested				: Ok
 */	
bool CXML::GetNodeText(CString csPathToNode,CString csAttribute,CString csAttValue,CString &rcsValue,bool bCurrentNodeAsBase)
{
	CString csPath;

	IXMLDOMNode * pNode  = NULL;

	IXMLDOMNode *pINodeData = NULL;
	
	if(!GetNode(&pINodeData,csPathToNode,csAttribute,csAttValue,bCurrentNodeAsBase))
		return false;

	BSTR bstrNodeText;

	m_hr = pINodeData->get_text(&bstrNodeText);
	pINodeData->Release();
	if (!SUCCEEDED(m_hr) || !bstrNodeText)
		return false;

	rcsValue = bstrNodeText;

	SysFreeString(bstrNodeText);
	return true;
}

/*
	 Function name		: CXML::NextSibling
	 Description	    : This will move to the current node to the sibling of the current node.
						: if no more sibling is available retruns false.
	 Return type		: bool 
	 Tested				: Ok
 */	
bool CXML::NextSibling()
{
	if(!m_pICurrentNode) 
		return false;

	IXMLDOMNode * pITempNode = m_pICurrentNode;
	IXMLDOMNode * pNode = NULL;
	pITempNode->AddRef();

	m_hr = pITempNode->get_nextSibling(&pNode);
	pITempNode->Release();
	if (!SUCCEEDED(m_hr)|| !pNode)
		return false;

	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = NULL;
	}

	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();
	
	pNode->Release();

	return true;
}

/*
	 Function name		: CXML::PreviousSibling
	 Description	    : This will move the current node to the previous sibling of the current node.
	 Return type		: bool 
	 Tested				: Ok
*/	
bool CXML::PreviousSibling()
{
	if(!m_pICurrentNode) 
		return false;

	IXMLDOMNode * pITempNode = m_pICurrentNode;
	IXMLDOMNode * pNode = NULL;

	pITempNode->AddRef();

	m_hr = pITempNode ->get_previousSibling(&pNode);
	pITempNode->Release();
	if (!SUCCEEDED(m_hr) || !pNode)
		return false;

	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode= NULL;
	}

	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();

	pNode->Release();
	return true;
}

/*
	 Function name		: CXML::MoveToParentNode
	 Description	    : This function will move to the n th parent the current node.
	 Return type		: bool
	 Argument			: UINT nNthParent
	 Tested				: Ok
*/	
bool CXML::MoveToParentNode(UINT nNthParent)
{
	if(!m_pICurrentNode) 
		return false;

	IXMLDOMNode * pITempNode = m_pICurrentNode;
	IXMLDOMNode * pNode = NULL;
	pITempNode->AddRef();

	for(UINT i=0;i<nNthParent;++i)
	{
		if(pNode)
		{
			pNode ->Release();
			pNode = NULL;
		}

		m_hr = pITempNode ->get_parentNode(&pNode);
		if (!SUCCEEDED(m_hr) || !pNode)
		{
			pITempNode->Release();
			return false;
		}

		if(pITempNode)
		{
			pITempNode->Release();
			pITempNode  = NULL;
		}

		pITempNode = pNode;
		pITempNode->AddRef();
	}

	if(pNode)
	{
		pITempNode->Release();
		m_pICurrentNode->Release();
		m_pICurrentNode = pNode;
		m_pICurrentNode->AddRef();
		pNode->Release();
		pNode= NULL;
	}
	return true;
}

/*
	 Function name		: CXML::HasChildNode
	 Description	    : This will return true if the current node has child node
	 Return type		: bool 
	 Tested				: Ok
 */	

bool CXML::HasChildNode()
{
	VARIANT_BOOL bHasChild = FALSE;
	if(!m_pICurrentNode)
		return false;

	m_hr = m_pICurrentNode->hasChildNodes(&bHasChild);
	if (!SUCCEEDED(m_hr))
		return false;

	if(bHasChild == TRUE)
		return true;
	else
		return false;
}

/*
	 Function name		: CXML::HasAttributes
	 Description	    : This function retruns true if it has attributes
						: node of the currentnode
	 Return type		: bool 
	 Tested				: Ok
*/

bool CXML::HasAttributes()
{
	if(!m_pICurrentNode)
		return false;

	IXMLDOMNamedNodeMap * pAttributeMap = 0;

	m_hr = m_pICurrentNode->get_attributes(&pAttributeMap);
	if (!SUCCEEDED(m_hr))
			return false;

	long nCount = 0;
	m_hr = pAttributeMap->get_length(&nCount);

	pAttributeMap->Release();

	if (!SUCCEEDED(m_hr))
			return false;

	return nCount != 0;
}

/*
	 Function name		: CXML::NextChildNode
	 Description	    : This function moves the current node to the Next Element type child 
						: node of the currentnode
	 Return type		: bool 
	 Tested				: Ok
*/

bool CXML::NextChildNode()
{
	if(!m_pICurrentNode)
		return false;

	IXMLDOMNode * pNode = NULL;
	IXMLDOMNode * pITempNode = m_pICurrentNode;
	pITempNode->AddRef();

	IXMLDOMNodeList * pChildList = NULL;
	
	// Get the list of child nodes of the current node

	m_hr = pITempNode->get_childNodes(&pChildList);
	pITempNode->Release();
	if (!SUCCEEDED(m_hr))
		return false;
	// loop through the childs
	DOMNodeType nodeType;
	while(true)
	{
		// Get the node type of each child, if it is of NODE_ELEMENT type set it as current node
		m_hr = pChildList->nextNode(&pNode);
		if(!SUCCEEDED(m_hr))
		{
			pChildList->Release();
			return false;
		}
		if(!pNode) break;
		m_hr = pNode->get_nodeType(&nodeType);
		if(!SUCCEEDED(m_hr))
		{
			pChildList->Release();
			pNode->Release();
			return false;
		}

		if(nodeType == NODE_ELEMENT)
			break;
		if(pNode)
			pNode->Release();
	}

	if(pChildList)
		pChildList->Release();

	if(pNode)
	{
		if(m_pICurrentNode)
		{
			m_pICurrentNode->Release();
			m_pICurrentNode = NULL;
		}

		m_pICurrentNode = pNode;
		m_pICurrentNode->AddRef();

		pNode->Release();
		return true;
	}
	return false;
	
}


/*
	 Function name		: CXML::GoToNode
	 Description	    : This function moves the current node to the node according to the pathtonode
						: searching for the node starts either from the current node
						: or it may start from the Root Node depending on the value of 
						: bool bUseBase.

	 Return type		: bool 
 	 Argument			: CString csPathToNode
 	 Argument			: bool bCurrentNodeAsBase 
	Tested				: Ok
 */	
bool CXML::GoToNode(CString csPathToNode,bool bCurrentNodeAsBase)
{
	CString csPath;
	IXMLDOMNode * pNode  = NULL;


	if(GetNode(&pNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
	{
		if(m_pICurrentNode)
		{
			m_pICurrentNode->Release();
			m_pICurrentNode = NULL;
		}
		m_pICurrentNode = pNode;
		m_pICurrentNode->AddRef();
		pNode->Release();
		
		return true;
	}

	return false;
}


// Function name	: CXML::GoToNodeEx
// Description	    : This Function can be used to moveto a purticular node same as the 
//					: GoToNode functions.The
// Return type		: bool 
// Argument         : CString csPathToNode
// Argument         : char **ppTagNames
// Argument         : char** ppAttributes
// Argument         : char **ppValues
// Argument         : int nTagCount
// Argument         : bool bCurrentNodeAsBase

bool CXML::GoToNodeEx(CString csPathToNode,char **ppTagNames,char** ppAttributes,char **ppValues,int nTagCount,bool bCurrentNodeAsBase)
{
	CString csPath;
	IXMLDOMNode *pBaseNode = NULL;
	
	if(!ppTagNames && !ppAttributes && !ppValues)
		return false;

	if(bCurrentNodeAsBase)
	{
		if(!m_pICurrentNode) return false;

		pBaseNode = m_pICurrentNode;
		pBaseNode->AddRef();
		csPath = ".";
	}
	else
	{
		if(!m_pIRootNode) return false;

		pBaseNode = m_pIRootNode;
		pBaseNode->AddRef();
		csPath = "";
	}
	
	int nNextIndex = 0,nLastIndex = 0;

	
	for(int i=0;i<nTagCount;++i)
	{
		if(nNextIndex > csPathToNode.GetLength())
			break;
		nLastIndex = csPathToNode.Find(ppTagNames[i],nNextIndex);
		if(nLastIndex<0)
			return false;
		if(nLastIndex>nNextIndex)
		{
			CString csTemp = csPathToNode.Mid(nNextIndex,(nLastIndex-nNextIndex)-1);
			csPath +="/";
			csPath += csTemp;
		}
		nNextIndex = nLastIndex + strlen(ppTagNames[i])+1;
		CString csTag;
		csTag.Format("/%s[@%s = \"%s\"]",ppTagNames[i],ppAttributes[i],ppValues[i]);
		csPath += csTag;
	}
	

	BSTR bstrPath = csPath.AllocSysString();

	IXMLDOMNode * pNode = NULL;
	m_hr = pBaseNode->selectSingleNode(bstrPath,&pNode);
	pBaseNode->Release();
	SysFreeString(bstrPath);

	if(!SUCCEEDED(m_hr) || !pNode)
		return false;
	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = NULL;
	}
	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();
	pNode->Release();	
	return true;

}
/*
	Function name	: CXML::GoToNode
	Description	    : Moves to the node having the specified text
	Return type		: bool 
	Argument        : CString csPathToNode
	Argument        : CString csNodeText
	Argument        : bool bCurrentNodeAsBase
	Tested			: Not working
*/
bool CXML::GoToNodeEx(CString csPathToNode,CString csNodeText,bool bCurrentNodeAsBase)
{
	CString csPath;
	IXMLDOMNode *pBaseNode = NULL;
	
	if(bCurrentNodeAsBase)
	{
		if(!m_pICurrentNode) return false;

		pBaseNode = m_pICurrentNode;
		pBaseNode->AddRef();
		csPath.Format("./%s[.= \"%s\"]",csPathToNode,csNodeText);
	}
	else
	{
		if(!m_pIRootNode) return false;
		pBaseNode = m_pIRootNode;
		pBaseNode->AddRef();
		csPath.Format("/%s[.= \"%s\"]",csPathToNode,csNodeText);
	}

	BSTR bstrPath = csPath.AllocSysString();

	IXMLDOMNode * pNode = NULL;
	m_hr = pBaseNode->selectSingleNode(bstrPath,&pNode);
	pBaseNode->Release();
	SysFreeString(bstrPath);

	if(!SUCCEEDED(m_hr) || !pNode)
		return false;


	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = NULL;
	}
	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();
	pNode->Release();	
	return true;
}

/*
	 Function name		: CXML::GoToNode
	 Description	    : This function moves the current node to the node according to the pathtonode
						: searching for the node starts either from the current node
						: or it may start from the Root Node depending on the value of 
						: bool bCurrentNodeAsBase.

	 Return type		: bool 
 	 Argument			: CString csPathToNode
     Argument			: CString csAttribute
	 Argument			: CString csValue
 	 Argument			: bool bCurrentNodeAsBase
	 Tested				: Ok
 */	
bool CXML::GoToNode(CString csPathToNode,CString csAttribute,CString csValue,bool bCurrentNodeAsBase)
{

	CString csPath;
	IXMLDOMNode * pNode  = NULL;

	if(GetNode(&pNode,csPathToNode,csAttribute,csValue,bCurrentNodeAsBase))
	{
		if(m_pICurrentNode)
		{
			m_pICurrentNode->Release();
			m_pICurrentNode = NULL;
		}
		m_pICurrentNode = pNode;
		m_pICurrentNode->AddRef();
		pNode->Release();
		
		return true;
	}
	return false;
}


/*
	 Function name		: CXML::GetCurrentNodeName
	 Description	    : This function gets the name of the current node 
	 Return type		: bool
	 Argument			: CString & rcsNodeName
	 Tested				: Ok
*/	
bool CXML::GetCurrentNodeName(CString & rcsNodeName)
{
	if(!m_pICurrentNode) 
		return false;

	BSTR bstrNodeText;
	m_hr =	m_pICurrentNode->get_nodeName(&bstrNodeText);	
	if(!SUCCEEDED(m_hr))
		return false;

	rcsNodeName = bstrNodeText;	
	SysFreeString(bstrNodeText);
	return true;
}


/*
	 Function name		: CXML::DeleteNode
	 Description	    : This function deletes the node described in the path 
						: searching for the node starts either from the current node
						: or it may start from the Root Node depending on the value of 
						: bool bCurrentNodeAsBase. 

	 Return type		: bool 
 	 Argument			: CString csPathToNode
 	 Argument			: bool bCurrentNodeAsBase
	 Tested				: Ok
*/	

bool CXML::DeleteNode(CString csPathToNode,bool bCurrentNodeAsBase)
{
	if(csPathToNode.IsEmpty()) return false;
	
	IXMLDOMNode * pRemoveNode = NULL;
		
	if(!GetNode(&pRemoveNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
		return false;

	bool bRet = Delete(&pRemoveNode);
	
	pRemoveNode->Release();

	return bRet;
}

/*
	 Function name		: CXML::DeleteNode
	 Description	    : This function will delete the node described in the path 
						: searching for the node starts either from the current node
						: or it may start from the Root Node depending on the value of 
						: bool bCurrentNodeAsBase. 

	 Return type		: bool 
 	 Argument			: CString csPathToNode
	 Argument			: CString csAttribute
	 Argument			: CString csValue
 	 Argument			: bool bCurrentNodeAsBase
	 Tested				: Ok
 */	

bool CXML::DeleteNode(CString csPathToNode,CString csAttribute,CString csValue,bool bUseBase)
{
	if(csPathToNode.IsEmpty()) return false;
	
	IXMLDOMNode * pRemoveNode = NULL;
		
	if(!GetNode(&pRemoveNode,csPathToNode,csAttribute,csValue,bUseBase))
		return false;

	bool bRet = Delete(&pRemoveNode);

	if(pRemoveNode)
		pRemoveNode->Release();

	return bRet;
}

/*
	 Function name		: CXML::DeleteNode
	 Description	    : This function will delete the current node 
	 Return type		: bool 
	 Tested				: Ok
 */	
bool CXML::DeleteNode()
{
	if(!m_pICurrentNode)
		return false;

	IXMLDOMNode * pNode = NULL;

	m_hr = m_pICurrentNode->get_nextSibling(&pNode);	
	if (!SUCCEEDED(m_hr))		
		return false;

	if(!pNode)
	{
		m_hr = m_pICurrentNode->get_parentNode(&pNode);
		if (!SUCCEEDED(m_hr))
			return false;
	}
	if(!pNode)
		return false;
	
	Delete(&m_pICurrentNode);
	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = NULL;
	}
	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();
	pNode->Release();
	return true;
}
/*
	 Function name		: CXML::Delete
	 Description	    : This helper function delete the node supplied node
	 Return type		: bool 
	 Argument			: IXMLDOMNode **ppRemoveNode
	 Tested				: Ok
 */	
bool CXML::Delete(IXMLDOMNode **ppRemoveNode)
{
	if(!(*ppRemoveNode)) return false;

	IXMLDOMNode * pParentNode = NULL;
	IXMLDOMNode * pRemovedNode = NULL;

	m_hr = (*ppRemoveNode)->get_parentNode(&pParentNode );
	if(!SUCCEEDED(m_hr) || !pParentNode)
		return false;


	m_hr = pParentNode->removeChild(*ppRemoveNode,&pRemovedNode);
	pParentNode->Release();
	if(!SUCCEEDED(m_hr) || !pRemovedNode)
		return false;

	pRemovedNode->Release();
	return true;
}

/*
	 Function name		: CXML::CreateElement
	 Description	    : This function create an element node set it as the current Node
						: with attributes and value and the text supplied 
	 Return type		: bool 
	 Argument			: IXMLDOMNode **ppRemoveNode
 */	
bool CXML::CreateElement(CString csTagName,LPCTSTR lpszText,char ** ppAttributes,char ** ppValues,int nNoOfAttributes,bool bSetAsCurNode)
{
	IXMLDOMNode * pNode = NULL;
	if(csTagName.IsEmpty())
		return false;

	if(!m_pICurrentNode)
		return false;

	_variant_t vtNodeType((long)NODE_ELEMENT);
	_bstr_t bstrName(csTagName);
	_bstr_t bstrNameSpace("");

	m_hr = m_pXMLDoc->createNode(vtNodeType,bstrName,bstrNameSpace,&pNode);
	if(!SUCCEEDED(m_hr))
		return false;

	if(m_pINewElement)
	{
		m_pINewElement->Release();
		m_pINewElement = NULL;
	}


	if(!AddNode(&m_pICurrentNode,&pNode,&m_pINewElement,NODE_ELEMENT))
	{
		pNode->Release();
		return false;
	} 

	if(!m_pINewElement)
		return false;

	if(lpszText)
	{
		_bstr_t bstrData(lpszText);

		m_hr = pNode->put_text(bstrData);
		if(!SUCCEEDED(m_hr))
		{
			pNode->Release();
			return false;
		}
	}

	pNode->Release();

	if(nNoOfAttributes && ppAttributes && ppValues )
	{
		for(int i = 0;i<nNoOfAttributes;++i)
		{
			if(!CreateAttributeNode(&m_pINewElement,ppAttributes[i],ppValues[i]))
				return false;
		}
	}

	if(bSetAsCurNode)
	{
		if(m_pICurrentNode)
		{
			m_pICurrentNode->Release();
			m_pICurrentNode = NULL;

		}
		m_pICurrentNode = m_pINewElement;
		m_pICurrentNode->AddRef();
	}
	return true;
}


/*
	 Function name		: CXML::CreateAttribute
	 Description	    : This function adds an attribute to the current node
						: with attributes and value and the text supplied 
	 Return type		: bool 
	 Argument			: CString csAttribute
	 Argument			: CString csValue
	 Tested				: Ok
 */	

bool CXML::CreateAttribute(CString csAttribute,CString csValue)
{
	return CreateAttributeNode(&m_pICurrentNode,csAttribute,csValue);
}

/*
	Function name	: CXML::CreateAttribute
	Description	    : This function adds an attribute to the given node
					: with attributes and value and the text supplied 
	Return type		: bool 
	Argument        : CString  csPathToNode
	Argument        : CString csAttribute
	Argument        : CString csValue
	Argument        : bool bCurrentNodeAsBase
*/
bool CXML::CreateAttribute(CString  csPathToNode,CString csAttribute,CString csValue,bool bCurrentNodeAsBase)
{
	IXMLDOMNode * pNode = NULL;
	if(!GetNode(&pNode,csPathToNode,NULL,NULL,bCurrentNodeAsBase))
		return false;

	bool bRet = CreateAttributeNode(&pNode,csAttribute,csValue);
	
	pNode->Release();
	return bRet;
}

/*
	 Function name		: CXML::CreateComment
	 Description	    : This function creates a comment node
	 Return type		: bool 
	 Argument			: CString csComment
	 Tested				: Ok
*/	
bool CXML::CreateComment(CString csComment)
{
	return CreateCommentNode(&m_pICurrentNode,csComment);
}

/*
	 Function name		: CXML::CreateTextNode
	 Description	    : This helper function create an attribute to the node supplied as argumnet
	 Return type		: bool 
	 Argument			: IXMLDOMNode **pParentNode
 	 Argument			: CString csAttribute
 	 Argument			: CString csValue
 */	
bool CXML::RemoveAttributeNode(IXMLDOMNode **pParentNode,CString csAttribute)
{
	IXMLDOMNode * pNode = NULL;
	if(csAttribute.IsEmpty())
		return false;

	if(!(*pParentNode))
		return false;
	
	IXMLDOMNamedNodeMap * pAttributes = NULL;
	m_hr = (*pParentNode)->get_attributes(&pAttributes);
	
	if(!SUCCEEDED(m_hr) || !pAttributes)
		return false;

	IXMLDOMNode *pRemovedNode = NULL;
	_bstr_t bstrAttribute(csAttribute);
	
	m_hr = pAttributes->removeNamedItem(bstrAttribute,&pRemovedNode);
	
	pAttributes->Release();
	if(!SUCCEEDED(m_hr) || !pRemovedNode)
		return false;

	pRemovedNode->Release();
	return true;
}

/*
	Function name	: CXML::CreateAttributeNode
	Description	    : 
	Return type		: bool 
	Argument        : IXMLDOMNode **pParentNode
	Argument        : CString csAttribute
	Argument        : CString csValue
	Tested			: Ok
*/
bool CXML::CreateAttributeNode(IXMLDOMNode **pParentNode,CString csAttribute,CString csValue)
{
	IXMLDOMNode * pNode = NULL;
	if(csAttribute.IsEmpty())
		return false;

	if(!(*pParentNode))
		return false;

	_variant_t vtNodeType((long)NODE_ATTRIBUTE);

	_bstr_t bstrName(csAttribute);
	_bstr_t bstrNameSpace("");

	m_hr = m_pXMLDoc->createNode(vtNodeType,bstrName,bstrNameSpace,&pNode);
	if(!SUCCEEDED(m_hr))
		return false;

	IXMLDOMNamedNodeMap * pAttributes = NULL;
	m_hr = (*pParentNode)->get_attributes(&pAttributes);
	
	if(!SUCCEEDED(m_hr) || !pAttributes)
	{
		pNode->Release();
		return false;
	}

	IXMLDOMNode *pNewNode = NULL;
	m_hr = pAttributes->setNamedItem(pNode,&pNewNode);

	pNode->Release();
	pAttributes->Release();
	if(!SUCCEEDED(m_hr) || !pNewNode)
		return false;

	
	_variant_t vtValue(csValue);
	m_hr =	pNewNode->put_nodeValue(vtValue);

	pNewNode->Release();
	if(!SUCCEEDED(m_hr) || !pNewNode)
		return false;

	return true;
}

/*
	 Function name		: CXML::CreateCommentNode
	 Description	    : This helper function creates a comment for the node supplied as argumnet
	 Return type		: bool 
	 Argument			: IXMLDOMNode **pParentNode
 	 Argument			: CString csComment
*/
bool CXML::CreateCommentNode(IXMLDOMNode **ppParentNode,CString &rcsComment)
{
	if(rcsComment.IsEmpty()) 
		return false;
	if(!(*ppParentNode)) 
		return false;

	IXMLDOMNode * pNode = NULL;
	
	_variant_t vtNodeType((long)VT_I4,NODE_COMMENT);
	_bstr_t bstrNameSpace("");

	m_hr = m_pXMLDoc->createNode(vtNodeType,bstrNameSpace,bstrNameSpace,&pNode);
	if(!SUCCEEDED(m_hr))
		return false;
			

	_variant_t vtComment(rcsComment);
	m_hr = pNode->put_nodeValue(vtComment);
	if(!SUCCEEDED(m_hr))
	{
		pNode->Release();
		return false;
	}

	IXMLDOMNode * pINewNode = NULL;	
	bool bRet = AddNode(&m_pICurrentNode,&pNode,&pINewNode,NODE_COMMENT);
	if(pNode)
		pNode->Release();
	if(pINewNode)
		pINewNode->Release();

	return bRet;
}

/*
	 Function name		: CXML::Save
	 Description	    : This function saves the changes made to the loaded XML file
						: if a file name is supplied the changes will be stored in the new file
						 : else it will be saved in the old file.
	 Return type		: bool 
	 Argument			: LPCTSTR lpszFileName
	 Tested				: Ok
*/	
bool CXML::Save(LPCTSTR lpszFileName)
{
	CString csFile;

	if(lpszFileName)
		csFile = lpszFileName;
	else if(!m_csXmlFileName.IsEmpty())
		csFile = m_csXmlFileName;
	else
		return false;

	_variant_t vtFileName(csFile);
	m_hr = m_pXMLDoc->save(vtFileName);

	if(!SUCCEEDED(m_hr))
		return false;

return true;
}

/*
	 Function name		: CXML::AddNode
	 Description	    : This helper function append the supplied node to the DOM
	 Return type		: bool 
	 Argument			: IXMLDOMNode **pParentNode
 	 Argument			: IXMLDOMNode **ppINodeToAdd
	 Argument			: IXMLDOMNode **ppINewNode
	 Argument			: DOMNodeType nodeType
	 Argument			: AddPos ePos
	 Tested				: Ok
*/	
bool CXML::AddNode(IXMLDOMNode **ppParentNode,IXMLDOMNode **ppINodeToAdd,IXMLDOMNode **ppINewNode,DOMNodeType nodeType,AddPos ePos)
{
	if( !(*ppINodeToAdd) || !(*ppParentNode))
		return false;


	DOMNodeType ndType;
	ePos = APPEND;

	(*ppINodeToAdd)->get_nodeType(&ndType);
	if(nodeType != ndType)
		return false;
	
	_variant_t oVar;
	oVar.vt = VT_NULL;
	
	if(ePos == LEFT)
		m_hr = (*ppParentNode)->insertBefore(*ppINodeToAdd,oVar,ppINewNode);
	else if(ePos == APPEND)
		m_hr = (*ppParentNode)->appendChild(*ppINodeToAdd,ppINewNode);
	

	if(SUCCEEDED(m_hr)||(*ppINewNode))
		return true;	
	
return false;	
}

/*
	Function name	: CXML::GetNoOfChildNodes
	Description	    :Get the no of childs of the current node 
	Return type		: bool 
	Argument        : long &nNodes
	Tested			: Ok
*/
bool CXML::GetNoOfChildNodes(long &nNodes)
{
	if(!m_pICurrentNode)
		return false;

	IXMLDOMNodeList * pNodeList = NULL;

	m_hr = m_pICurrentNode->get_childNodes(&pNodeList);

	if(!SUCCEEDED(m_hr ) || !pNodeList)
		return false;

	m_hr = pNodeList->get_length(&nNodes);

	if(!SUCCEEDED(m_hr ))
		return false;
	else
		return true;
}

/*
	Function name	: CXML::GetCurrentNode
	Description	    : 
	Return type		: IXMLDOMNode *
	Tested			: Ok
*/

IXMLDOMNode * CXML::GetCurrentNode()
{	
	if(!m_pICurrentNode)
		return NULL;
	m_pICurrentNode->AddRef();
	return m_pICurrentNode;
}

/*
	Function name	: CXML::CloneNode
	Description	    : Clones the  current node and return the new pointer,
					: Release the pointer after use.
	Return type		: IXMLDOMNode *
	Tested			: Ok
*/
IXMLDOMNode * CXML::CloneNode()
{
	if(!m_pICurrentNode)
		return 0;

	IXMLDOMNode * pClonedNode = 0;
	m_hr = m_pICurrentNode->cloneNode(VARIANT_TRUE,&pClonedNode);

	return pClonedNode;
}
/*
	Function name	: CXML::SetCurrentNode
	Description	    : 
	Return type		: bool 
	Argument        : IXMLDOMNode * pXMLDOMNode
	Tested			: Ok
*/
bool CXML::SetCurrentNode(IXMLDOMNode * pXMLDOMNode)
{
	if(! pXMLDOMNode)
		return false;

	if(m_pICurrentNode)
		m_pICurrentNode->Release();
	
	m_pICurrentNode = pXMLDOMNode;
	m_pICurrentNode->AddRef();
	pXMLDOMNode->Release();
	
	return true;
}


/*
	Function name	: CXML::SetNode
	Description	    : Inserts a node into the curretly loaded xml
	Return type		: bool 
	Argument        : IXMLDOMNode *pIDomNode
	Tested			: ok
*/
bool CXML::SetNode(IXMLDOMNode *pIDomNode)
{
	if(!pIDomNode || !m_pICurrentNode)
		return false;

	IXMLDOMNode *pINewNode = NULL;
	_variant_t oVar;
	oVar.vt = VT_NULL;
	
	m_hr = m_pICurrentNode->insertBefore(pIDomNode,oVar,&pINewNode);
	
	if(!SUCCEEDED(m_hr ) || !pINewNode)
		return false;
	
	pIDomNode->Release();
	pINewNode->Release();
	return true;
}


/*
	Function name	: CXML::GetNodesList
	Description	    : retrieves the list of nodes with the given name
	Return type		: bool 
	Argument        : CString csPathToNode
	Argument        : bool bCurrentNodeAsBase
*/
bool CXML::GetNodesList(CString csPathToNode,bool bCurrentNodeAsBase)
{
	CString csPath;
	IXMLDOMNode *pBaseNode = NULL;
	
	if(bCurrentNodeAsBase)
	{
		if(!m_pICurrentNode) return false;

		pBaseNode = m_pICurrentNode;
		pBaseNode->AddRef();
		csPath.Format("./%s",csPathToNode);
	}
	else
	{
		if(!m_pIRootNode) return false;
		pBaseNode = m_pIRootNode;
		pBaseNode->AddRef();
		csPath.Format("/%s",csPathToNode);
	}

	_bstr_t bstrPath(csPath);

	if(m_pNodeList)
	{
		m_pNodeList->Release();
		m_pNodeList = NULL;
	}

	m_hr = pBaseNode->selectNodes(bstrPath,&m_pNodeList);
	pBaseNode->Release();
	if(!SUCCEEDED(m_hr) || !m_pNodeList)
		return false;

	return true;
}

/* 
	Function name	: CXML::GetItemsCount
	Description	    : Gives the no  of items in the list
	Return type		: bool 
	Argument        : long * pnCount
*/

bool CXML::GetItemsCount(long * pnCount)
{
	if(!m_pNodeList) return false;

	m_hr = m_pNodeList->get_length(pnCount);
	if(!SUCCEEDED(m_hr))
		return false;
	else
		return true;
}


/*
	Function name	: CXML::ResetList
	Description	    : Reset the list
	Return type		: bool 
*/
bool CXML::ResetList()
{
	if(!m_pNodeList) return false;
	
	m_hr = m_pNodeList->reset();

	if(!SUCCEEDED(m_hr))
		return false;
	else
		return true;

}

/*
	Function name	: CXML::NextNodeInList
	Description	    : 
	Return type		: bool 
	Tested			: ok
*/
bool CXML::NextNodeInList()
{
	if(!m_pNodeList) return false;

	IXMLDOMNode * pNode = NULL;

	m_hr = m_pNodeList->nextNode(&pNode);	
	if(!SUCCEEDED(m_hr) || !pNode)
		return false;

	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = 0;
	}

	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();
	pNode->Release();

	return true;
}

/*
	Function name	: CXML::NodeInList
	Description	    : retrieves the n th node in list
	Return type		: bool 
	Argument        : long nIndex
*/
bool CXML::NodeInList(long nIndex)
{
	if(!m_pNodeList) return false;

	IXMLDOMNode * pNode = NULL;

	m_hr = m_pNodeList->get_item(nIndex,&pNode);
	if(!SUCCEEDED(m_hr) || !pNode)
		return false;

	if(m_pICurrentNode)
	{
		m_pICurrentNode->Release();
		m_pICurrentNode = 0;
	}

	m_pICurrentNode = pNode;
	m_pICurrentNode->AddRef();
	pNode->Release();

	return true;
}


#ifdef USETREECTRL

bool CXML::Populate(CTreeCtrl &treeCtrl)
{
	m_pTreeCtrl = &treeCtrl;
	Looop(m_pIRootNode,TVI_ROOT,TVI_FIRST);
	return true;
}

void CXML::Looop(IXMLDOMNode * pCurrentNode,HTREEITEM hParent,HTREEITEM hInsertAfter)
{
	if(!pCurrentNode)
		return;
	
	CString csText;
	GetNodeName(&pCurrentNode,csText);
	TVINSERTSTRUCT insertStruct;
	insertStruct.hParent = hParent;
	insertStruct.hInsertAfter = hInsertAfter;
	insertStruct.item.mask = TVIF_TEXT;
	insertStruct.item.pszText = (char *)(LPCTSTR)csText;
	insertStruct.item.cchTextMax = csText.GetLength();
	HTREEITEM hTreeItem = m_pTreeCtrl->InsertItem(&insertStruct);

	Looop(NextChildNode(&pCurrentNode),hTreeItem,TVI_FIRST);
	hTreeItem = m_pTreeCtrl->GetParentItem(hTreeItem);
	Looop(NextSib(&pCurrentNode),hTreeItem,TVI_LAST);
}



bool CXML::GetNodeName(IXMLDOMNode **ppNode,CString & rcsNodeName)
{
	if(!(*ppNode)) 
		return false;

	BSTR bstrNodeText;
	m_hr =	(*ppNode)->get_nodeName(&bstrNodeText);	
	if(!SUCCEEDED(m_hr))
		return false;

	rcsNodeName = bstrNodeText;	
	SysFreeString(bstrNodeText);
	return true;
}

IXMLDOMNode *CXML::NextSib(IXMLDOMNode **ppNode)
{
	if(!(*ppNode))
		return NULL;

	IXMLDOMNode * pNode = NULL;
	m_hr = (*ppNode)->get_nextSibling(&pNode);
	if (!SUCCEEDED(m_hr)|| !pNode)
		return NULL;
	return pNode; 

}

IXMLDOMNode *CXML::NextChildNode(IXMLDOMNode **ppNode)
{
	if(!(*ppNode))
		return NULL;

	IXMLDOMNode * pNode = NULL;
	IXMLDOMNodeList * pChildList = NULL;
	
	// Get the list of child nodes of the current node

	m_hr = (*ppNode)->get_childNodes(&pChildList);
	if (!SUCCEEDED(m_hr))
		return NULL;
	// loop through the childs
	DOMNodeType nodeType;
	while(true)
	{
		// Get the node type of each child, if it is of NODE_ELEMENT type set it as current node
		m_hr = pChildList->nextNode(&pNode);
		if(!SUCCEEDED(m_hr))
		{
			pChildList->Release();
			return NULL;
		}
		if(!pNode) break;
		m_hr = pNode->get_nodeType(&nodeType);
		if(!SUCCEEDED(m_hr))
		{
			pChildList->Release();
			pNode->Release();
			return NULL;
		}

		if(nodeType == NODE_ELEMENT)
			break;
		if(pNode)
			pNode->Release();
	}

	if(pChildList)
		pChildList->Release();

	return pNode;
}

#endif

//////////////////////////////////////////////////////////////////////////////////////////////


/*	IXMLDOMNode * pParentNode = NULL;
	
	m_hr = (*ppRefNode)->get_parentNode(&pParentNode);

	if(!SUCCEEDED(m_hr)||!pParentNode)
		return false;	*/
