$NetBSD: patch-bin_dig_dighost.c,v 1.2 2013/09/21 15:59:01 taca Exp $

Avoid to use true as variable name.

--- bin/dig/dighost.c.orig	2013-09-05 05:19:53.000000000 +0000
+++ bin/dig/dighost.c
@@ -4313,7 +4313,7 @@ prepare_lookup(dns_name_t *name)
 		isc_result_t result;
 		isc_region_t r;
 		dns_rdataset_t *rdataset = NULL;
-		isc_boolean_t true = ISC_TRUE;
+		isc_boolean_t isc_true = ISC_TRUE;
 #endif
 
 		memset(namestr, 0, DNS_NAME_FORMATSIZE);
@@ -4327,7 +4327,7 @@ prepare_lookup(dns_name_t *name)
 
 		result = advanced_rrsearch(&rdataset, &ns.name,
 					   dns_rdatatype_aaaa,
-					   dns_rdatatype_any, &true);
+					   dns_rdatatype_any, &isc_true);
 		if (result == ISC_R_SUCCESS) {
 			for (result = dns_rdataset_first(rdataset);
 			     result == ISC_R_SUCCESS;
@@ -4356,7 +4356,7 @@ prepare_lookup(dns_name_t *name)
 
 		rdataset = NULL;
 		result = advanced_rrsearch(&rdataset, &ns.name, dns_rdatatype_a,
-					   dns_rdatatype_any, &true);
+					   dns_rdatatype_any, &isc_true);
 		if (result == ISC_R_SUCCESS) {
 			for (result = dns_rdataset_first(rdataset);
 			     result == ISC_R_SUCCESS;
@@ -4475,11 +4475,11 @@ isc_result_t
 initialization(dns_name_t *name)
 {
 	isc_result_t   result;
-	isc_boolean_t  true = ISC_TRUE;
+	isc_boolean_t  isc_true = ISC_TRUE;
 
 	chase_nsrdataset = NULL;
 	result = advanced_rrsearch(&chase_nsrdataset, name, dns_rdatatype_ns,
-				   dns_rdatatype_any, &true);
+				   dns_rdatatype_any, &isc_true);
 	if (result != ISC_R_SUCCESS) {
 		printf("\n;; NS RRset is missing to continue validation:"
 		       " FAILED\n\n");
@@ -4827,7 +4827,7 @@ sigchase_td(dns_message_t *msg)
 	isc_result_t result;
 	dns_name_t *name = NULL;
 	isc_boolean_t have_answer = ISC_FALSE;
-	isc_boolean_t true = ISC_TRUE;
+	isc_boolean_t isc_true = ISC_TRUE;
 
 	if ((result = dns_message_firstname(msg, DNS_SECTION_ANSWER))
 	    == ISC_R_SUCCESS) {
@@ -4836,7 +4836,7 @@ sigchase_td(dns_message_t *msg)
 			initialization(name);
 			return;
 		}
-		have_answer = true;
+		have_answer = isc_true;
 	} else {
 		if (!current_lookup->trace_root_sigchase) {
 			result = dns_message_firstname(msg,
@@ -4954,7 +4954,7 @@ sigchase_td(dns_message_t *msg)
 						   dns_rdatatype_rrsig,
 						   current_lookup
 						   ->rdtype_sigchase,
-						   &true);
+						   &isc_true);
 			if (result == ISC_R_FAILURE) {
 				printf("\n;; RRset is missing to continue"
 				       " validation SHOULD NOT APPEND:"
@@ -4967,7 +4967,7 @@ sigchase_td(dns_message_t *msg)
 						   &chase_authority_name,
 						   dns_rdatatype_rrsig,
 						   dns_rdatatype_any,
-						   &true);
+						   &isc_true);
 			if (result == ISC_R_FAILURE) {
 				printf("\n;; RRSIG is missing  to continue"
 				       " validation SHOULD NOT APPEND:"
@@ -5043,7 +5043,7 @@ sigchase_td(dns_message_t *msg)
 					   &chase_authority_name,
 					   dns_rdatatype_rrsig,
 					   dns_rdatatype_ds,
-					   &true);
+					   &isc_true);
 		if (result != ISC_R_SUCCESS) {
 			printf("\n;; DSset is missing to continue validation:"
 			       " FAILED\n\n");
@@ -5131,7 +5131,7 @@ sigchase_td(dns_message_t *msg)
 		result = advanced_rrsearch(&chase_rdataset, &chase_name,
 					   current_lookup->rdtype_sigchase,
 					   dns_rdatatype_any ,
-					   &true);
+					   &isc_true);
 	if (result == ISC_R_FAILURE) {
 		printf("\n;; RRsig of RRset is missing to continue validation"
 		       " SHOULD NOT APPEND: FAILED\n\n");
@@ -5174,7 +5174,7 @@ getneededrr(dns_message_t *msg)
 	dns_name_t *name = NULL;
 	dns_rdata_t sigrdata = DNS_RDATA_INIT;
 	dns_rdata_sig_t siginfo;
-	isc_boolean_t   true = ISC_TRUE;
+	isc_boolean_t   isc_true = ISC_TRUE;
 
 	if ((result = dns_message_firstname(msg, DNS_SECTION_ANSWER))
 	    != ISC_R_SUCCESS) {
@@ -5190,7 +5190,7 @@ getneededrr(dns_message_t *msg)
 	if (chase_rdataset == NULL) {
 		result = advanced_rrsearch(&chase_rdataset, name,
 					   dns_rdatatype_any,
-					   dns_rdatatype_any, &true);
+					   dns_rdatatype_any, &isc_true);
 		if (result != ISC_R_SUCCESS) {
 			printf("\n;; No Answers: Validation FAILED\n\n");
 			return (ISC_R_NOTFOUND);
@@ -5310,7 +5310,7 @@ getneededrr(dns_message_t *msg)
 		result = advanced_rrsearch(&chase_sigdsrdataset,
 					   &chase_signame,
 					   dns_rdatatype_rrsig,
-					   dns_rdatatype_ds, &true);
+					   dns_rdatatype_ds, &isc_true);
 		if (result == ISC_R_FAILURE) {
 			printf(";; WARNING : NO RRSIG DS : RRSIG DS"
 			       " should come with DS\n");
