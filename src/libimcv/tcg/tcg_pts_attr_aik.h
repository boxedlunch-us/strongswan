/*
 * Copyright (C) 2011 Sansar Choinyambuu
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup tcg_pts_attr_aik tcg_pts_attr_aik
 * @{ @ingroup tcg_pts_attr_aik
 */

#ifndef TCG_PTS_ATTR_AIK_H_
#define TCG_PTS_ATTR_AIK_H_

typedef struct tcg_pts_attr_aik_t tcg_pts_attr_aik_t;

#include "tcg_attr.h"
#include "pa_tnc/pa_tnc_attr.h"

/**
 * Class implementing the TCG PTS Attestation Identity Key attribute
 *
 */
struct tcg_pts_attr_aik_t {

	/**
	 * Public PA-TNC attribute interface
	 */
	pa_tnc_attr_t pa_tnc_attribute;
	
	/**
	 * Get Naked Public Key flag
	 *
	 * @return				Naked Public Key flag
	 */
	bool (*get_naked_flag)(tcg_pts_attr_aik_t *this);

	/**
	 * Set Naked Public Key flag
	 *
	 * @param naked				flag
	 */
	void (*set_naked_flag)(tcg_pts_attr_aik_t *this, 
				bool naked);
	
	/**
	 * Get AIK
	 *
	 * @return				Attestation Identity Key
	 */
	chunk_t (*get_aik)(tcg_pts_attr_aik_t *this);

	/**
	 * Set AIK
	 *
	 * @param flags				set of flags
	 */
	void (*set_aik)(tcg_pts_attr_aik_t *this, 
				chunk_t aik);
};

/**
 * Creates an tcg_pts_attr_aik_t object
 * 
 * @param naked_pub_aik			Sender only has naked public key
 * @param aik				Attestation Identity Key
 */
pa_tnc_attr_t* tcg_pts_attr_aik_create(bool naked_pub_aik, chunk_t aik);

/**
 * Creates an tcg_pts_attr_aik_t object from received data
 *
 * @param value				unparsed attribute value
 */
pa_tnc_attr_t* tcg_pts_attr_aik_create_from_data(chunk_t value);

#endif /** TCG_PTS_ATTR_AIK_H_ @}*/
