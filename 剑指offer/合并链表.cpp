ListNode* mergeList(ListNode* phead1,ListNode* phead2)
{
	if(phead1==NULL && phead2==NULL) return NULL;
	
	if(phead1==NULL)
	{
		return phead2;
	}
	else if(pead2==NULL)
	{
		return phead1;
	}
	
	ListNode* Merge=NULL;
	
	while(phead1 && phead2)
	{
		if(phead1->data<phead2-data)
		{
			Merge=phead1;
			Merge->next=mergeList(phead1->next,phead2);	
		}
		else
		{
			Merge=head2;
			Merge->next=mergrList(phead1,phead2->next);
		}	
	} 
}



ListNode *Merge(ListNode* phead1,ListNode *phead2)
{ 

	if(phead1 == NULL && phead2 == NULL) return NULL; 

	if(phead1 == NULL)return phead2;else if(phead2 == NULL) return phead1;             ListNode *pMerge = NULL;  ListNode * phead = NULL;int count = 0; 
	while(phead1 && phead2) 
	{ 
	if(phead1->data <= phead2->data) 
	{
	 pMerge->next = phead1;
	 phead1= phead1->next;
	}
  	else 
	{
	  pMerge->next = phead2;
	  phead2 = phead2->next;
	}
  	if(count == 0) phead = pMerge;count++;
  	pMerge = pMerge->next;
	}
	if(phead1 == NULL) pMerge->next = phead2;
	else pMerge->next = phead1;
	return phead;
}
